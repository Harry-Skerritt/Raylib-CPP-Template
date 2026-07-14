//
// Created by Harry Skerritt on 14/07/2026.
//

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include "raylib.h"
#include <cstdlib>

class StorageManager {
public:
    static inline bool DoesFileExist(const char* data_file) {
        int data_size = 0;
        unsigned char *file_data = LoadFileData(data_file, &data_size);
        return (file_data != nullptr);
    }

    static inline bool SaveStorageValue(const char* data_file, const unsigned int position, const int value) {
        bool success = false;
        int data_size = 0;
        unsigned int new_data_size = 0;
        unsigned char *file_data = LoadFileData(data_file, &data_size);
        unsigned char *new_file_data = nullptr;

        if (file_data != nullptr) {
            if (data_size <= position*sizeof(int)) {
                new_data_size = (position + 1)*sizeof(int);
                new_file_data = static_cast<unsigned char *>(RL_REALLOC(file_data, new_data_size));

                if (new_file_data != nullptr) {
                    const auto data_ptr = reinterpret_cast<int *>(new_file_data);
                    data_ptr[position] = value;
                }
                else {
                    TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to realloc data (%u), position in bytes (%u) bigger than actual file size", data_file, data_size, position*sizeof(int));

                    new_file_data = file_data;
                    new_data_size = data_size;
                }
            } else {
                new_file_data = file_data;
                new_data_size = data_size;

                const auto data_ptr = reinterpret_cast<int *>(new_file_data);
                data_ptr[position] = value;
            }

            success = SaveFileData(data_file, new_file_data, new_data_size);
            RL_FREE(file_data);

            TraceLog(LOG_INFO, "FILEIO: [%s] Saved storage value: %i", data_file, value);
        } else {
            TraceLog(LOG_INFO, "FILEIO: [%s] File created successfully", data_file);

            data_size = (position + 1)*sizeof(int);
            file_data = static_cast<unsigned char *>(RL_MALLOC(data_size));
            const auto dataPtr = reinterpret_cast<int *>(file_data);
            dataPtr[position] = value;

            success = SaveFileData(data_file, file_data, data_size);
            UnloadFileData(file_data);

            TraceLog(LOG_INFO, "FILEIO: [%s] Saved storage value: %i", data_file, value);
        }

        return success;
    }

    static inline int LoadStorageValue(const char* data_file,const unsigned int position) {
        int value = 0;
        int data_size = 0;
        unsigned char* file_data = LoadFileData(data_file, &data_size);

        if (file_data != nullptr) {
            if (data_size < static_cast<int>(position * 4)) TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to find storage position: %i", data_file, position);
            else
            {
                const auto data_ptr = reinterpret_cast<int *>(file_data);
                value = data_ptr[position];
            }

            UnloadFileData(file_data);

            TraceLog(LOG_INFO, "FILEIO: [%s] Loaded storage value: %i", data_file, value);
        }

        return value;
    }
};

#endif //STORAGEMANAGER_H

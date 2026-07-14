//
// Created by Harry Skerritt on 14/07/2026.
//

#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

struct GameContext {
    int target_fps{};
    bool quit_flag{};
};

struct StorageContext {
    // -- Data File Names Here --

    static StorageContext& GetInstance() {
        static StorageContext instance;
        return instance;
    }

    StorageContext(const StorageContext&) = delete;
    void operator=(const StorageContext&) = delete;

private:
    StorageContext() = default;
};



enum class StorageData {
    // -- Data Storage Positions Here --
};
#endif //GAMECONTEXT_H

//
// Created by Harry Skerritt on 07/07/2026.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <iostream>

#include "raylib.h"
#include <map>
#include <string>
#include <__ostream/basic_ostream.h>

class AssetManager {
private:
    static std::map<std::string, Font> fonts;
    static std::map<std::string, Texture> textures;
    static std::map<std::string, Sound> sounds;
    static std::map<std::string, Music> music;

public:
    // Fonts
    static void LoadFontKey(std::string key, const char* path, int font_size) {
        fonts[key] = LoadFontEx(path, font_size, nullptr, 0);
        SetTextureFilter(fonts[key].texture, TEXTURE_FILTER_BILINEAR);
    }

    static Font& GetFont(std::string key) {
        return fonts[key];
    }

    // Textures
    static void LoadTextureKey(std::string key, const char* path) {
        textures[key] = LoadTexture(path);
    }

    static Texture& GetTexture(std::string key) {
        return textures[key];
    }

    // Sounds
    static void LoadSoundKey(std::string key, const char* path) {
        sounds[key] = LoadSound(path);
    }

    static Sound& GetSound(std::string key) {
        return sounds[key];
    }

    // Music
    static void LoadMusicKey(std::string key, const char* path) {
        music[key] = LoadMusicStream(path);
    }

    static Music& GetMusic(const std::string key) {
        return music.at(key);
    }


    static void UnloadAll() {
        std::cout << "[AssetManager] Unloading all assets..." << std::endl;
        for (auto& pair : fonts) {
            UnloadFont(pair.second);
        }
        fonts.clear();

        for (auto& pair : textures) {
            UnloadTexture(pair.second);
        }
        textures.clear();

        for (auto& pair : sounds) {
            UnloadSound(pair.second);
        }
        sounds.clear();

        for (auto& pair : music) {
            UnloadMusicStream(pair.second);
        }
        music.clear();
    }
};



#endif //ASSETMANAGER_H

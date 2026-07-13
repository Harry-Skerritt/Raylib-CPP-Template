//
// Created by Harry Skerritt on 12/07/2026.
//

#include <iostream>
#include "Game.h"
#include "raylib.h"
#include "../Managers/AssetManager/AssetManager.h"
#include "../Scenes/GameScene/GameScene.h"
#include "../Scenes/Splash/Splash.h"

Game::Game(const int window_width, const int window_height, const char *window_title, const int target_fps, const bool use_splash) {
    InitWindow(window_width, window_height, window_title);
    InitAudioDevice();
    SetTargetFPS(target_fps);
    m_is_running = true;

    loadTextures();
    loadFonts();
    loadSounds();
    loadMusic();

    // Load Initial Scene
    if (use_splash) m_scene_manager.setScene(std::make_unique<Splash>(m_scene_manager));
    else  m_scene_manager.setScene(std::make_unique<GameScene>(m_scene_manager));
}

Game::~Game() {
    AssetManager::UnloadAll();
};


void Game::init() {
    std::cout << "Initializing Game ..." << std::endl;
}

void Game::update() {
    if (WindowShouldClose()) m_is_running = false;
    m_scene_manager.update(GetFrameTime());

}

void Game::render() {
    DrawFPS(10, 10);
    m_scene_manager.render();
}

void Game::renderUI() const {
    m_scene_manager.renderUI();
}

// Loaders
void Game::loadTextures() {
    std::cout << "Loading textures..." << std::endl;
    AssetManager::LoadTextureKey("raylib-logo", "resources/raylib.png");
}

void Game::loadFonts() {
    std::cout << "Loading fonts ..." << std::endl;
}

void Game::loadSounds() {
    std::cout << "Loading sounds..." << std::endl;
}

void Game::loadMusic() {
    std::cout << "Loading music..." << std::endl;
}

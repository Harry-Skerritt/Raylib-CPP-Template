//
// Created by Harry Skerritt on 12/07/2026.
//

#include <iostream>
#include "Game.h"
#include "raylib.h"
#include "../Managers/AssetManager/AssetManager.h"
#include "../Managers/GestureHandler/GestureHandler.h"
#include "../Scenes/GameScene/GameScene.h"
#include "../Scenes/Splash/Splash.h"

Game::Game(const int window_width, const int window_height, const char *window_title, const int target_fps, const bool use_splash) {
    InitWindow(window_width, window_height, window_title);
    InitAudioDevice();
    SetTargetFPS(target_fps);
    m_global_context.target_fps = target_fps;
    m_is_running = true;

    loadTextures();
    loadFonts();
    loadSounds();
    loadMusic();

    // Load Initial Scene
    if (use_splash) m_scene_manager.replaceScene(std::make_unique<Splash>(m_scene_manager, m_global_context));
    else  m_scene_manager.replaceScene(std::make_unique<GameScene>(m_scene_manager, m_global_context));
}

Game::~Game() {
    AssetManager::UnloadAll();
    CloseAudioDevice();
    CloseWindow();
};


void Game::init() {
    TraceLog(LOG_INFO, "GAME: Initializing Game ...");
}

void Game::update() {
    if (WindowShouldClose() || m_global_context.quit_flag) m_is_running = false;
    GestureHandler::Update();
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
    TraceLog(LOG_INFO, "GAME: Loading textures...");
    AssetManager::LoadTextureKey("raylib-logo", "resources/raylib.png");
}

void Game::loadFonts() {
    TraceLog(LOG_INFO, "GAME: Loading fonts ...");
}

void Game::loadSounds() {
    TraceLog(LOG_INFO, "GAME: Loading sounds...");
}

void Game::loadMusic() {
    TraceLog(LOG_INFO, "GAME: Loading music...");
}

//
// Created by Harry Skerritt on 12/07/2026.
//

#include "Game.h"
#include "raylib.h"

Game::Game(const int window_width, const int window_height, const char *window_title, const int target_fps) {
    InitWindow(window_width, window_height, window_title);
    SetTargetFPS(target_fps);
    m_is_running = true;
}

Game::~Game() = default;


void Game::init() {
    m_raylib_texture = LoadTexture("resources/raylib.png");
}

void Game::update() {
    if (WindowShouldClose()) m_is_running = false;
}

void Game::render() {
    DrawFPS(10, 10);

    Vector2 img_pos = {
        static_cast<float>(GetScreenWidth()) / 2 - static_cast<float>(m_raylib_texture.width) / 2,
        static_cast<float>(GetScreenHeight()) / 2 - static_cast<float>(m_raylib_texture.height) / 2 };

    DrawTexture(m_raylib_texture, static_cast<int>(img_pos.x), static_cast<int>(img_pos.y) - 50, WHITE);

    const auto text_width = MeasureText("Hello, World!", 40);
    DrawText("Hello, World!",
        GetScreenWidth() / 2 - text_width / 2, GetScreenHeight() / 2 + 100, 40, BLACK);
}

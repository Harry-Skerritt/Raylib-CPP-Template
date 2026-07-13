//
// Created by Harry Skerritt on 13/07/2026.
//

#include "GameScene.h"

#include "../../Game/Game.h"
#include "../../Managers/AssetManager/AssetManager.h"

GameScene::GameScene(SceneManager& manager, Game& game) : Scene(manager, game) {
    m_raylib_texture = AssetManager::GetTexture("raylib-logo");
}

GameScene::~GameScene() {

}


void GameScene::update(float dt) {

}

void GameScene::render() {
    Vector2 img_pos = {
        static_cast<float>(GetScreenWidth()) / 2 - static_cast<float>(m_raylib_texture.width) / 2,
        static_cast<float>(GetScreenHeight()) / 2 - static_cast<float>(m_raylib_texture.height) / 2 };

    DrawTexture(m_raylib_texture, static_cast<int>(img_pos.x), static_cast<int>(img_pos.y) - 50, WHITE);

    const auto text_width = MeasureText("Hello, World!", 40);
    DrawText("Hello, World!",
        GetScreenWidth() / 2 - text_width / 2, GetScreenHeight() / 2 + 100, 40, BLACK);
}

void GameScene::renderUI() {

}


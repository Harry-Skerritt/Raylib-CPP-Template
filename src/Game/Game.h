//
// Created by Harry Skerritt on 12/07/2026.
//

#ifndef GAME_H
#define GAME_H
#include <raylib.h>

#include "GameContext.h"
#include "../Managers/SceneManager/SceneManager.h"

class Game {
public:
    Game(int window_width, int window_height, const char* window_title, int target_fps = 1000, bool use_splash = true);
    ~Game();

    void init();
    void update();
    void render();
    void renderUI() const;

    [[nodiscard]] bool isRunning() const { return m_is_running; }

private:
    bool m_is_running = true;
    SceneManager m_scene_manager;
    GameContext m_global_context;

    // --- Loaders ---
    void loadTextures();
    void loadFonts();
    void loadSounds();
    void loadMusic();
};

#endif //GAME_H

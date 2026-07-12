//
// Created by Harry Skerritt on 12/07/2026.
//

#ifndef GAME_H
#define GAME_H
#include <raylib.h>

class Game {
public:
    Game(const int window_width, const int window_height, const char* window_title, const int target_fps = 1000);
    ~Game();

    void init();
    void update();
    void render();

    [[nodiscard]] bool isRunning() const { return m_is_running; }

private:
    bool m_is_running = true;

    Texture2D m_raylib_texture;
};

#endif //GAME_H

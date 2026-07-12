#include <iostream>
#include "raylib.h"
#include "Game/Game.h"

Game* game = nullptr;

int main() {
    game = new Game(1280, 720, "2048", 60);
    game->init();

    while (game->isRunning()) {
        game->update();

        BeginDrawing();
            ClearBackground(BLACK);
            game->render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

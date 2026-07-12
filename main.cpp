#include <iostream>
#include "raylib.h"

int main() {
    InitWindow(1280, 720, "Raylib Game Template");
    SetTargetFPS(60);
    std::cout << "Window Loaded!" << std::endl;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        const auto text_width = MeasureText("Hello, World!", 40);
        DrawText("Hello, World!",
            GetScreenWidth() / 2 - text_width / 2, GetScreenHeight() / 2 - 20, 40, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
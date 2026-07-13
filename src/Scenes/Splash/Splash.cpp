//
// Created by Harry Skerritt on 13/07/2026.
//

#include "Splash.h"
#include <iostream>
#include "raylib.h"
#include "../../Managers/SceneManager/SceneManager.h"
#include "../GameScene/GameScene.h"

Splash::Splash(SceneManager& manager, Game& game) : Scene(manager, game) {
    logoPositionX = GetScreenWidth() / 2 - 128;
    logoPositionY = GetScreenHeight() / 2 - 128;
}

Splash::~Splash() {}

void Splash::update(float dt) {
    if (state == 0)
    {
        framesCounter++;

        if (framesCounter == 120)
        {
            state = 1;
            framesCounter = 0;
        }
    }
    else if (state == 1)
    {
        topSideRecWidth += 4;
        leftSideRecHeight += 4;

        if (topSideRecWidth == 256) state = 2;
    }
    else if (state == 2)
    {
        bottomSideRecWidth += 4;
        rightSideRecHeight += 4;

        if (bottomSideRecWidth == 256) state = 3;
    }
    else if (state == 3)
    {
        framesCounter++;

        if (framesCounter >= 12)
        {
            lettersCount++;
            framesCounter = 0;
        }

        if (lettersCount >= 10)
        {
            alpha -= 0.02f;

            if (alpha <= 0.0f)
            {
                alpha = 0.0f;
                state = 4;
            }
        }
    }
    else if (state == 4)
    {
        if (!transition_started) {
            m_scene_manager.setScene(std::make_unique<GameScene>(m_scene_manager, m_game), TransitionType::FADE_TO_WHITE);
            transition_started = true;
        }
    }
}

void Splash::render() {
    ClearBackground(RAYWHITE);
    if (state == 0)
    {
        if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
    }
    else if (state == 1)
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
    }
    else if (state == 2)
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

        DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
    }
    else if (state == 3)
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

        DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, alpha));

        for (int i = 0; i < lettersCount && i < 6; i++) {
            buffer[i] = "raylib"[i];
        }

        DrawText(buffer, GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, alpha));
    }
}

void Splash::renderUI() {}




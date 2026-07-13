//
// Created by Harry Skerritt on 13/07/2026.
//

// Adapted from https://www.raylib.com/examples/shapes/loader.html?name=shapes_logo_raylib_anim

#ifndef SPLASH_H
#define SPLASH_H
#include "../../Managers/SceneManager/Scene.h"


class Splash : public Scene {
public:
    Splash(SceneManager& manager, GameContext& context);
    ~Splash() override;

    void update(float dt) override;
    void render() override;
    void renderUI() override;

private:
    int logoPositionX;
    int logoPositionY;

    int framesCounter = 0;
    int lettersCount = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;

    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;
    char buffer[10] = { 0 };

    int state = 0;
    float alpha = 1.0f;

    bool transition_started = false;
};



#endif //SPLASH_H

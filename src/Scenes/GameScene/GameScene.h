//
// Created by Harry Skerritt on 13/07/2026.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <raylib.h>
#include "../../Managers/SceneManager/Scene.h"



class GameScene : public Scene {
public:
    GameScene(SceneManager& manager, Game& game);
    ~GameScene() override;

    void update(float dt) override;
    void render() override;
    void renderUI() override;

private:
    Texture2D m_raylib_texture;

};



#endif //GAMESCENE_H

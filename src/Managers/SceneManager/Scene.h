//
// Created by Harry Skerritt on 13/07/2026.
//

#ifndef SCENE_H
#define SCENE_H
#include "../../Game/GameContext.h"
class SceneManager;

class Scene {
public:
    explicit Scene(SceneManager& manager, GameContext& context) : m_scene_manager(manager), m_context(context) {}
    virtual ~Scene() = default;

    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual void renderUI() = 0;

protected:
    SceneManager& m_scene_manager;
    GameContext& m_context;

};

#endif //SCENE_H

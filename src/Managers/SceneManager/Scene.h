//
// Created by Harry Skerritt on 13/07/2026.
//

#ifndef SCENE_H
#define SCENE_H
class SceneManager;
class Game;

class Scene {
public:
    explicit Scene(SceneManager& manager, Game& game) : m_scene_manager(manager), m_game(game) {}
    virtual ~Scene() = default;

    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual void renderUI() = 0;

protected:
    SceneManager& m_scene_manager;
    Game& m_game;

};

#endif //SCENE_H

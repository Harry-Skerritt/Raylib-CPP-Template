//
// Created by Harry Skerritt on 13/07/2026.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include "Scene.h"

enum class TransitionType { SNAP, FADE };
enum class ManagerState { IDLE, FADING_IN, FADING_OUT };

class SceneManager {
public:
    void setScene(std::unique_ptr<Scene> new_scene, TransitionType type = TransitionType::SNAP);
    void update(float dt);
    void render() const;
    void renderUI() const;

private:
    std::unique_ptr<Scene> m_active_scene;
    std::unique_ptr<Scene> m_next_scene;

    ManagerState m_state = ManagerState::IDLE;
    TransitionType m_transition_type = TransitionType::SNAP;
    float m_fade_alpha = 0.0f;
    const float m_fade_speed = 2.0f;
    void handleFadeUpdate(float dt);
};

#endif //SCENEMANAGER_H

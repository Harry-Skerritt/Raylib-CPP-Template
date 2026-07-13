//
// Created by Harry Skerritt on 13/07/2026.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include "Scene.h"
#include <raylib.h>
#include <functional>

enum class TransitionType {
    SNAP,
    FADE_TO_BLACK,
    FADE_TO_WHITE,
    CROSS_FADE
};

enum class ManagerState { IDLE, FADING_IN, FADING_OUT, CROSSFADING };

class SceneManager {
public:
    SceneManager() = default;
    ~SceneManager() {
        if (m_transition_target.id != 0) UnloadRenderTexture(m_transition_target);
    }
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

    // Fade To Black
    void handleFadeUpdate(float dt);

    // Crossfade
    RenderTexture2D m_transition_target = { 0 };
    void handleCrossFadeUpdate(float dt);
    void drawFadedTexture(const std::function<void(Scene*)>& renderFunc) const;
};
#endif //SCENEMANAGER_H

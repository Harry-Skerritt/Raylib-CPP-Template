//
// Created by Harry Skerritt on 13/07/2026.
//

#include "SceneManager.h"
#include <raylib.h>

void SceneManager::setScene(std::unique_ptr<Scene> new_scene, TransitionType type) {
    m_next_scene = std::move(new_scene);
    m_transition_type = type;

    if (type == TransitionType::SNAP) {
        m_active_scene = std::move(m_next_scene);
    } else {
        m_state = ManagerState::FADING_OUT;
        m_fade_alpha = 0.0f;
    }
}

void SceneManager::update(const float dt) {
    handleFadeUpdate(dt);

    if (m_active_scene && m_state != ManagerState::FADING_OUT) {
        m_active_scene->update(dt);
    }
}

void SceneManager::render() const {
    if (m_active_scene) m_active_scene->render();

    if (m_state != ManagerState::IDLE) {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, m_fade_alpha));
    }
}

void SceneManager::renderUI() const {
    if (m_active_scene) m_active_scene->renderUI();
}



// Private
void SceneManager::handleFadeUpdate(const float dt) {
    if (m_state == ManagerState::FADING_OUT) {
        m_fade_alpha += dt * m_fade_speed;
        if (m_fade_alpha >= 1.0f) {
            m_fade_alpha = 1.0f;
            m_active_scene = std::move(m_next_scene);
            m_state = ManagerState::FADING_IN;
        }
    } else if (m_state == ManagerState::FADING_IN) {
        m_fade_alpha -= dt * m_fade_speed;
        if (m_fade_alpha <= 0.0f) {
            m_fade_alpha = 0.0f;
            m_state = ManagerState::IDLE;
        }
    }
}




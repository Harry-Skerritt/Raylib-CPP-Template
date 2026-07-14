//
// Created by Harry Skerritt on 13/07/2026.
//

#include "SceneManager.h"
#include <raylib.h>

void SceneManager::replaceScene(std::unique_ptr<Scene> new_scene, TransitionType type) {
    TraceLog(LOG_INFO, "SCENE_MANAGER: Replacing Scene...");
    m_replace_pending = true;
    pushScene(std::move(new_scene), type);
}

void SceneManager::pushScene(std::unique_ptr<Scene> new_scene, TransitionType type) {
    TraceLog(LOG_INFO, "SCENE_MANAGER: Pushing Scene...");
    m_next_scene = std::move(new_scene);
    m_transition_type = type;

    if (type == TransitionType::SNAP) {
        m_scene_stack.push_back(std::move(m_next_scene));
    }
    else if (type == TransitionType::FADE_TO_BLACK || type == TransitionType::FADE_TO_WHITE) {
        m_state = ManagerState::FADING_OUT;
        m_fade_alpha = 0.0f;
    }
    else if (type == TransitionType::CROSS_FADE) {
        m_state = ManagerState::CROSSFADING;
        m_fade_alpha = 0.0f;
        if (m_transition_target.id == 0)
            m_transition_target = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    }
}

void SceneManager::popScene() {
    TraceLog(LOG_INFO, "SCENE_MANAGER: Popping Scene...");
    if (!m_scene_stack.empty()) {
        m_scene_stack.pop_back();
    }
}

void SceneManager::update(const float dt) {
    handleFadeUpdate(dt);
    handleCrossFadeUpdate(dt);

    if (!m_scene_stack.empty() && m_state != ManagerState::FADING_OUT) {
        m_scene_stack.back()->update(dt);
    }
}

void SceneManager::render() const {
    if (m_state == ManagerState::CROSSFADING) {
        drawFadedTexture([](Scene* s) { s->render(); });
    }
    else
    {
        if (!m_scene_stack.empty()) m_scene_stack.back()->render();

        if (m_state != ManagerState::IDLE) {
            const Color fade_color = (m_transition_type == TransitionType::FADE_TO_WHITE) ? WHITE : BLACK;
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(fade_color, m_fade_alpha));
        }
    }
}

void SceneManager::renderUI() const {
    if (m_state == ManagerState::CROSSFADING) {
        drawFadedTexture([](Scene* s) { s->renderUI(); });
    } else {
        if (!m_scene_stack.empty()) m_scene_stack.back()->renderUI();
    }
}


// Private
void SceneManager::handleFadeUpdate(const float dt) {
    if (m_state == ManagerState::FADING_OUT) {
        m_fade_alpha += dt * m_fade_speed;
        if (m_fade_alpha >= 1.0f) {
            m_fade_alpha = 1.0f;

            if (m_replace_pending) {
                m_scene_stack.clear();
                m_replace_pending = false;
            }

            m_scene_stack.push_back(std::move(m_next_scene));
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

// Crossfade
void SceneManager::handleCrossFadeUpdate(const float dt) {
    if (m_state == ManagerState::CROSSFADING) {
        m_fade_alpha += dt * m_fade_speed;
        if (m_fade_alpha >= 1.0f) {
            m_fade_alpha = 1.0f;

            if (m_replace_pending) {
                m_scene_stack.clear();
                m_replace_pending = false;
            }

            m_scene_stack.push_back(std::move(m_next_scene));
            m_state = ManagerState::IDLE;
        }
    }
}

void SceneManager::drawFadedTexture(const std::function<void(Scene *)> &renderFunc) const {
    if (!m_scene_stack.empty()) renderFunc(m_scene_stack.back().get());
    BeginTextureMode(m_transition_target);
    ClearBackground(BLANK);
    if (m_next_scene) renderFunc(m_next_scene.get());
    EndTextureMode();

    Rectangle src = { 0, 0, (float)m_transition_target.texture.width, -(float)m_transition_target.texture.height };
    DrawTextureRec(m_transition_target.texture, src, { 0, 0 }, Fade(WHITE, m_fade_alpha));
}




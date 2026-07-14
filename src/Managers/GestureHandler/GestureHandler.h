//
// Created by Harry Skerritt on 14/07/2026.
//

#ifndef GESTUREHANDLER_H
#define GESTUREHANDLER_H
#include "raylib.h"

class GestureHandler {
public:
    static void Update() {
        m_current_gesture = GetGestureDetected();
    }

    // Tapping
    static bool Tap() {
        if (m_current_gesture == GESTURE_TAP) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool DoubleTap() {
        if (m_current_gesture == GESTURE_DOUBLETAP) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool Hold() {
        if (m_current_gesture == GESTURE_HOLD) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool Drag() {
        if (m_current_gesture == GESTURE_DRAG) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    // Swiping
    static bool SwipeRight() {
        if (m_current_gesture == GESTURE_SWIPE_RIGHT) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool SwipeLeft() {
        if (m_current_gesture == GESTURE_SWIPE_LEFT) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool SwipeUp() {
        if (m_current_gesture == GESTURE_SWIPE_UP) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool SwipeDown() {
        if (m_current_gesture == GESTURE_SWIPE_DOWN) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    // Pinching
    static bool PinchIn() {
        if (m_current_gesture == GESTURE_PINCH_IN) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

    static bool PinchOut() {
        if (m_current_gesture == GESTURE_PINCH_OUT) {
            m_current_gesture = GESTURE_NONE;
            return true;
        }
        return false;
    }

private:
    static inline int m_current_gesture = GESTURE_NONE;
};

#endif //GESTUREHANDLER_H

#ifndef HAND_GESTURE_H
#define HAND_GESTURE_H

// Enum class to represent different types of hand gestures
enum class GestureType {
    NONE,          // No gesture detected
    SWIPE_LEFT,    // Swipe left gesture
    SWIPE_RIGHT,   // Swipe right gesture
    PINCH,         // Pinch gesture (for zooming)
    THUMBS_UP,     // Thumbs up gesture (for approval)
    OPEN_PALM,     // Open palm gesture (to stop an action)
    FIST,          // Fist gesture (to start an action)
    POINT          // Point gesture (for selection)
};

// HandGesture class responsible for detecting hand gestures
class HandGesture {
public:
    // Method to detect and return the current gesture
    GestureType detectGesture();
    // Constructor and other methods can be added as needed
};

#endif

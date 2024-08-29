#include "TaskManager.h"
#include <iostream>

// Method to execute tasks based on the detected gesture
void TaskManager::performTask(GestureType gesture) {
    // Switch statement to handle different gestures
    switch (gesture) {
        case GestureType::SWIPE_LEFT:
            std::cout << "Swiping Left...\n";
            // Add logic to navigate left (e.g., slides, images)
            break;
        case GestureType::SWIPE_RIGHT:
            std::cout << "Swiping Right...\n";
            // Add logic to navigate right
            break;
        case GestureType::PINCH:
            std::cout << "Pinching...\n";
            // Add logic to zoom in/out
            break;
        case GestureType::THUMBS_UP:
            std::cout << "Thumbs Up - Liking...\n";
            // Add logic for liking or approving an action
            break;
        case GestureType::OPEN_PALM:
            std::cout << "Open Palm - Stopping...\n";
            // Add logic to stop an ongoing action
            break;
        case GestureType::FIST:
            std::cout << "Fist - Starting...\n";
            // Add logic to start an action
            break;
        case GestureType::POINT:
            std::cout << "Pointing - Selecting...\n";
            // Add logic to select an item
            break;
        default:
            // Handle unknown gestures if necessary
            break;
    }
}

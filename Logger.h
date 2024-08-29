#ifndef LOGGER_H
#define LOGGER_H

#include "HandGesture.h" // Include the gesture definitions

// Logger class to log tasks performed based on gestures
class Logger {
public:
    // Log the task associated with the detected gesture
    void logTask(GestureType gesture);
};

#endif

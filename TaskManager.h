#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "HandGesture.h" // Include the gesture definitions

// TaskManager class to handle performing tasks based on detected gestures
class TaskManager {
public:
    // Perform the task associated with the detected gesture
    void performTask(GestureType gesture);
};

#endif

#include <iostream>             
#include "HandGesture.h"        // Gesture detection header
#include "TaskManager.h"        // Task management header
#include "Logger.h"             // Task logging header
#include "GestureCalibration.h" // Gesture calibration header

int main() {
    // Instantiate the main components of the system
    HandGesture gestureRecognizer;
    TaskManager taskManager;
    Logger logger;
    GestureCalibration calibrator;

    std::cout << "Initializing Hand Hero...\n";

    // Calibrate gestures before starting the main loop
    calibrator.calibrate();

    // Main loop to continuously detect and respond to gestures
    while (true) {
        // Detect the current gesture
        GestureType detectedGesture = gestureRecognizer.detectGesture();

        // If a gesture is detected, perform the corresponding task and log it
        if (detectedGesture != GestureType::NONE) {
            taskManager.performTask(detectedGesture);
            logger.logTask(detectedGesture);
        }
    }

    return 0; // Program should never reach this point under normal operation
}

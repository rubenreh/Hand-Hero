#include <iostream>
#include "HandGesture.h"
#include "TaskManager.h"
#include "Logger.h"
#include "GestureCalibration.h"

int main() {
    HandGesture gestureRecognizer;
    TaskManager taskManager;
    Logger logger;
    GestureCalibration calibrator;

    std::cout << "Initializing Hand Hero...\n";

    // Calibrate gestures before starting
    calibrator.calibrate();

    while (true) {
        GestureType detectedGesture = gestureRecognizer.detectGesture();

        if (detectedGesture != GestureType::NONE) {
            taskManager.performTask(detectedGesture);
            logger.logTask(detectedGesture);
        }
    }

    return 0;
}

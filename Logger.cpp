#include "Logger.h"
#include <iostream>
#include <fstream>

// Method to log the task performed to a file
void Logger::logTask(GestureType gesture) {
    // Open a file in append mode to keep adding logs
    std::ofstream logFile("gesture_log.txt", std::ios_base::app);

    // Check if the file is open successfully
    if (logFile.is_open()) {
        // Log the gesture performed, converting the gesture enum to an integer
        logFile << "Gesture performed: " << static_cast<int>(gesture) << "\n";
        logFile.close(); // Close the file after logging
    } else {
        // Handle file opening errors
        std::cerr << "Unable to open log file.\n";
    }
}

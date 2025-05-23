
// Author: Ruben Rehal

#include "motion_tracker.h"
#include <opencv2/opencv.hpp>
#include <iostream>

void MotionTracker::startTracking() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Camera not found." << std::endl;
        return;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::circle(frame, cv::Point(320, 240), 60, cv::Scalar(0, 255, 0), 4);
        cv::putText(frame, "Tracking Hand...", {20, 40}, cv::FONT_HERSHEY_SIMPLEX, 1, {0, 255, 255}, 2);

        cv::imshow("Hand Hero - Live Feed", frame);
        if (cv::waitKey(1) == 27) break; // Exit on 'Esc'
    }

    cap.release();
    cv::destroyAllWindows();
}

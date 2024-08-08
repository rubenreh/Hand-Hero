//Author: Ruben Rehal
//Date : July 28, 2024

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <wiringSerial.h> // For serial communication with Arduino

using namespace cv;
using namespace std;

// Function declarations
void processImage(Mat& image);
void findHandContours(Mat& mask, vector<vector<Point>>& contours);
bool isThumbsUp(const vector<Point>& contour, const vector<Vec4i>& defects);
bool isFist(const vector<Point>& contour, const vector<Vec4i>& defects);

int main() {
    // Open video capture
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        cerr << "Error: Unable to access the webcam" << endl;
        return -1;
    }

    // Open serial connection to Arduino
    int arduino = serialOpen("/dev/ttyUSB0", 9600); // Adjust to your port
    if (arduino < 0) {
        cerr << "Error: Unable to open serial connection" << endl;
        return -1;
    }

    Mat frame, hsvImage, mask;
    vector<vector<Point>> contours;

    while (true) {
        capture >> frame;
        if (frame.empty()) break;

        // Process image for hand detection
        processImage(frame);

        // Convert frame to HSV color space
        cvtColor(frame, hsvImage, COLOR_BGR2HSV);

        // Create a mask for skin color detection
        inRange(hsvImage, Scalar(0, 30, 60), Scalar(20, 150, 255), mask);

        // Find contours of the hand
        findHandContours(mask, contours);

        if (!contours.empty()) {
            // Find the largest contour
            size_t largestContourIdx = 0;
            double maxArea = 0;
            for (size_t i = 0; i < contours.size(); i++) {
                double area = contourArea(contours[i]);
                if (area > maxArea) {
                    maxArea = area;
                    largestContourIdx = i;
                }
            }

            vector<Point> handContour = contours[largestContourIdx];
            vector<int> hullIndices;
            vector<Vec4i> defects;

            // Calculate convex hull and defects
            convexHull(handContour, hullIndices, false);
            convexityDefects(handContour, hullIndices, defects);

            // Check for hand gestures
            if (isThumbsUp(handContour, defects)) {
                serialPutchar(arduino, 'U'); // Send 'U' command to Arduino
                cout << "Thumbs Up detected" << endl;
            } 
            else if (isFist(handContour, defects)) {
                serialPutchar(arduino, 'F'); // Send 'F' command to Arduino
                cout << "Fist detected" << endl;
            } 
            else {
                serialPutchar(arduino, 'S'); // Send 'S' command to stop
            }

            // Draw the contour and convex hull
            drawContours(frame, contours, largestContourIdx, Scalar(0, 255, 0), 2);
        }

        // Display the result
        imshow("Hand Tracking", frame);
        if (waitKey(30) >= 0) break;
    }

    // Close serial connection
    serialClose(arduino);
    return 0;
}

// Function to process the image
void processImage(Mat& image) {
    GaussianBlur(image, image, Size(5, 5), 0);
}

// Function to find hand contours in the mask
void findHandContours(Mat& mask, vector<vector<Point>>& contours) {
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
}

// Function to detect Thumbs Up gesture
bool isThumbsUp(const vector<Point>& contour, const vector<Vec4i>& defects) {
    // Simple heuristic for thumbs up (e.g., number of defects)
    return (defects.size() == 2 || defects.size() == 3); 
}

// Function to detect Fist gesture
bool isFist(const vector<Point>& contour, const vector<Vec4i>& defects) {
    // Simple heuristic for fist (e.g., no defects)
    return defects.size() == 0;
}

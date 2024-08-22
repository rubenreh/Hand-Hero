# Hand Hero

![Hand Hero Logo](https://github.com/rubenreh/Hand-Hero/blob/main/HandHeroLogo.png?raw=true)

**Hand Hero** is an assistive technology project aimed at enhancing accessibility for individuals with disabilities through intuitive hand gestures. This project combines hand gesture recognition with Arduino-based control to operate a motor, sound a buzzer, and illuminate an LED, making everyday tasks easier.

## Usage

1. **Run the C++ Application**: Launch the C++ program to start hand gesture recognition. The application will use the webcam to capture and analyze hand movements.
2. **Perform Gestures**:
   - **Thumbs Up**: The system will activate the motor to unlock a door and light up the LED.
   - **Fist**: The system will sound the buzzer and illuminate the LED in case of an emergency.
3. **Monitor Feedback**: Observe the responses of the motor, buzzer, and LED to ensure the system is working as expected.

## Features

- **Gesture Recognition**: Detects and interprets hand gestures using OpenCV.
- **Device Control**: Manages a motor, buzzer, and LED based on recognized gestures.
- **Assistive Technology**: Designed to provide intuitive control for individuals with disabilities.

## Components

- **Arduino**: Microcontroller used to control the motor, buzzer, and LED.
- **Webcam**: Captures real-time video for hand gesture detection.
- **OpenCV**: Library used for image processing and gesture recognition.
- **Motor**: Operates to open a door.
- **Buzzer**: Provides an alert sound.
- **LED**: Offers visual feedback.

## How It Works

1. **Hand Tracking**: Captures video from a webcam and processes it with OpenCV to detect hand gestures.
2. **Gesture Recognition**: Identifies gestures (e.g., thumbs up or fist) and communicates commands to the Arduino.
3. **Device Activation**: The Arduino interprets the commands to activate the motor, buzzer, and LED.

### Software Setup

1. **Arduino IDE**: Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software). Upload the Arduino code to your board.
2. **OpenCV**: Install OpenCV for C++ from the [OpenCV official website](https://opencv.org/releases/).
3. **Dependencies**: Ensure you have the necessary libraries for serial communication.

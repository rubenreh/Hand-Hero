# Hand Hero

<p align="center">
  <img src="https://github.com/rubenreh/Hand-Hero/blob/main/HandHeroLogo.png?raw=true" alt="Hand Hero Logo">
</p>

**Hand Hero** is an assistive technology project aimed at enhancing accessibility for individuals with disabilities through intuitive hand gestures. This project combines hand gesture recognition with Arduino-based control to operate a motor, sound a buzzer, and illuminate an LED, making everyday tasks easier.

## Usage

1. **Run the C++ Application**: Launch the C++ program to start hand gesture recognition. The application will use the webcam to capture and analyze hand movements.
2. **Perform Gestures**:
   - **Thumbs Up**: The system will activate the motor to unlock a door and light up the LED.
   - **Fist**: The system will sound the buzzer and illuminate the LED in case of an emergency.
3. **Monitor Feedback**: Observe the responses of the motor, buzzer, and LED to ensure the system is working as expected.

## **Features and Controls**

### **1. Gesture Recognition**
- **Simulated with Buttons:** The project uses buttons to simulate hand gestures for testing purposes. These buttons can be replaced with actual gesture sensors for a more advanced setup.
  - **Gesture Left Button:** Simulates a "Swipe Left" gesture to move the motor in the left direction.
  - **Gesture Right Button:** Simulates a "Swipe Right" gesture to move the motor in the right direction.
  - **Gesture Stop Button:** Simulates an "Open Palm" gesture to stop the motor.

### **2. Motor Control**
- **Direction Control:**
  - **Move Motor Left:** Activates when the "Swipe Left" gesture is detected, causing the motor to rotate in the left direction.
  - **Move Motor Right:** Activates when the "Swipe Right" gesture is detected, causing the motor to rotate in the right direction.
  - **Stop Motor:** Activates when the "Open Palm" gesture is detected, stopping the motor completely.

- **Speed Control:**
  - **Adjustable Speed:** The speed of the motor is controlled using Pulse Width Modulation (PWM). The motor speed can be adjusted by changing the PWM value sent to the motor driver.

### **3. Accessibility Enhancement**
- **Hands-Free Operation:** Designed to reduce physical strain by allowing users to control the motor through gestures, making it suitable for individuals with limited mobility or dexterity.
- **Intuitive Interaction:** Simplifies the control of devices or machinery by using hand gestures, providing a more user-friendly interface.

### **4. Modular Design**
- **Sensor Integration:** Can be expanded to include various gesture sensors (e.g., IR or ultrasonic) for real-time gesture detection.
- **Versatile Applications:** Adaptable for different use cases, from home automation to assistive devices.

### **5. User Feedback**
- **Serial Monitoring:** Provides real-time feedback on motor status (moving left, moving right, stopping) via the Arduino serial monitor, aiding in debugging and monitoring.

### **6. Customization**
- **Easy Configuration:** Users can easily modify the code to adjust motor speed, change gesture mappings, or integrate additional features based on their needs.

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

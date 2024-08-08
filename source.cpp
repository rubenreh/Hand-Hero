//Author: Ruben Rehal
//Date: July 28, 2024
//Arduino Code

// Pin Definitions
const int motorPin = 9;  // Motor control pin (e.g., Servo motor for door)
const int buzzerPin = 10; // Buzzer pin
const int ledPin = 13;   // LED pin

void setup() {
  // Set up pins
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Initialize all outputs to LOW
  digitalWrite(motorPin, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is available from serial port
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Process commands
    if (command == 'U') {
      // Thumbs Up detected
      digitalWrite(ledPin, HIGH);    // Turn on LED
      openDoor();                    // Activate motor to open door
    } 
    else if (command == 'F') {
      // Fist detected
      digitalWrite(ledPin, HIGH);    // Turn on LED
      soundAlarm();                 // Sound the buzzer
    } 
    else if (command == 'S') {
      // Stop all actions
      digitalWrite(motorPin, LOW);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
  }
}

void openDoor() {
  digitalWrite(motorPin, HIGH); // Activate the motor
  delay(5000);                  // Keep the door open for 5 seconds
  digitalWrite(motorPin, LOW);  // Deactivate the motor
}

void soundAlarm() {
  digitalWrite(buzzerPin, HIGH); // Sound the buzzer
  delay(5000);                   // Sound buzzer for 5 seconds
  digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
}

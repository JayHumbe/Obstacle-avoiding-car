#include <Servo.h>

// --- 1. PIN DEFINITIONS (Updated to your setup) ---

// Motor A (Left Side Connection)
const int in1 = 8;  
const int in2 = 9;  

// Motor B (Right Side Connection)
const int in3 = 10; 
const int in4 = 11; 

// Ultrasonic Sensor Pins
const int trigPin = 2; 
const int echoPin = 3; 

// Servo Motor Pin
const int servoPin = 4; 

// Create Servo Object
Servo myServo;

// Variables for logic
long duration;
int distance;
int safeDistance = 25; // Obstacle distance threshold in cm

void setup() {
  // --- 2. SETUP PINS ---
  
  // Motor pins as Outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach Servo and look forward
  myServo.attach(servoPin);
  myServo.write(90); // 90 degrees is "Center"
  delay(500); // Wait for servo to reach position
}

void loop() {
  // --- 3. MAIN LOOP LOGIC ---
  
  // Step 1: Check distance
  distance = readDistance();

  // Step 2: Decide movement
  if (distance < safeDistance) {
    // OBSTACLE DETECTED!
    stopCar();       
    delay(200);      // Brief pause
    
    moveBackward();  
    delay(500);      // Back up for 0.5 seconds
    
    stopCar();       
    delay(200);
    
    turnRight();     
    delay(600);      // Turn for 0.6 seconds (Adjust this number if it turns too much/little)
    
    stopCar();       
    delay(200);
  } 
  else {
    // PATH IS CLEAR
    moveForward();
  }
}

// --- 4. MOVEMENT FUNCTIONS ---

void moveForward() {
  // Left Motors Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Right Motors Forward
  // NOTE: If your right wheels spin backward, swap HIGH and LOW below
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void moveBackward() {
  // Left Motors Backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  // Right Motors Backward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  // To turn right: Left wheels go Forward, Right wheels go Backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopCar() {
  // Cut power to all motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

int readDistance() {
  // Send a ping
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  return duration * 0.034 / 2;
}

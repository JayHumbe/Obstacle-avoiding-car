# 🚗 Arduino Obstacle Avoiding Robot

An autonomous obstacle avoiding robot built using **Arduino**, **L298N Motor Driver**, **Ultrasonic Sensor (HC-SR04)**, **Servo Motor**, and **BO Motors**.

This project demonstrates real-time embedded decision making using sensor feedback and differential drive motor control.

---

## 📌 Project Overview

The robot continuously measures the distance to obstacles using an ultrasonic sensor.  

- If the path is clear → it moves forward  
- If an obstacle is detected within 25 cm → it stops, reverses, and turns right  

This system is based on reactive control logic and real-time sensor processing.

---

## 🧠 System Architecture

### 🔹 Components Used

- Arduino UNO / Nano
- L298N Motor Driver Module
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- 4 BO Motors
- Robot Chassis
- Battery Pack

---

## ⚙️ Working Principle

1. Ultrasonic sensor sends a trigger pulse.
2. Echo time is measured using `pulseIn()`.
3. Distance is calculated using:

   ```
   Distance = (Time × 0.034) / 2
   ```

4. If distance < 25 cm:
   - Stop
   - Move backward
   - Turn right
5. Else:
   - Move forward

The motor direction is controlled using the **H-Bridge configuration** inside the L298N motor driver.

---

## 🧾 Pin Configuration

| Component            | Arduino Pin |
|----------------------|------------|
| Motor A IN1         | 8          |
| Motor A IN2         | 9          |
| Motor B IN3         | 10         |
| Motor B IN4         | 11         |
| Ultrasonic TRIG     | 2          |
| Ultrasonic ECHO     | 3          |
| Servo Motor         | 4          |

---

## 🔌 Key Functions in Code

### `moveForward()`
Controls motors to move the robot forward.

### `moveBackward()`
Reverses motor direction.

### `turnRight()`
Implements differential drive logic:
- Left wheels → Forward  
- Right wheels → Backward  

### `readDistance()`
Triggers ultrasonic pulse and calculates distance in cm.

---

## 🚀 Features

- Real-time obstacle detection
- Differential drive turning
- Modular code structure
- Safe motor control using L298N
- Simple and scalable design

---

## 🔧 Possible Improvements

- Replace `delay()` with non-blocking `millis()` logic
- Add servo-based left-right scanning for smarter navigation
- Implement PID control for smoother turning
- Add Bluetooth or Wi-Fi control
- Add battery voltage monitoring

---

## 🛠 Challenges Faced

- Noise in ultrasonic readings
- Voltage drops during motor startup
- Motor vibrations affecting sensor stability

---

## 📚 Learning Outcomes

- H-Bridge motor control
- Embedded real-time logic
- Sensor interfacing
- Debugging hardware issues
- Power management basics

---

## 🎯 Future Scope

- Upgrade to ESP32 for IoT-based monitoring
- Add multiple sensors for advanced navigation
- Implement basic mapping logic
- Convert into an autonomous delivery bot

---

## 👨‍💻 Author

Jay Humbe  
Automation & Robotics Engineering  
Embedded Systems | AI | IoT Enthusiast  

---

⭐ If you found this project useful, feel free to star the repository!

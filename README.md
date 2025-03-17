# PostureGuard

# PostureGuard

**PostureGuard** is an innovative smart posture monitoring system designed to help you maintain optimal posture, prevent musculoskeletal disorders, and promote a healthier lifestyle. By combining advanced wearable sensor technology with a dynamic web-based dashboard, PostureGuard offers real-time feedback to keep your posture in check.

---

## Table of Contents

- [Overview](#overview)
- [Problem Statement](#problem-statement)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

---

## Overview

PostureGuard is a comprehensive solution that seamlessly integrates hardware and software. It uses an ESP8266 microcontroller and an MPU6050 sensor to continuously monitor your posture. Sensor data is processed in real time to compute key metrics like Posture Angle (with custom Z-axis mapping), Pitch, and Roll. The processed data is then served over Wi-Fi via an auto-updating web dashboard.

---

## Problem Statement

Poor posture during daily activities can lead to chronic pain, reduced mobility, and other musculoskeletal issues. **PostureGuard** aims to address this problem by providing:

- **Real-Time Monitoring:** Continuous tracking of your posture.
- **Actionable Feedback:** Immediate, easy-to-understand insights to help correct posture.
- **Preventive Healthcare:** Encouraging healthier postural habits to reduce long-term risks.

---

## Features

- **Smart Sensor Integration:**  
  - Utilizes an MPU6050 sensor for accurate motion tracking (accelerometer, gyroscope, and temperature data).
  
- **Real-Time Data Processing:**  
  - Computes:
    - **Posture Angle:** Remaps Z-axis data so that -9.8 m/s² is interpreted as +90° and 9.8 m/s² as -90°.
    - **Pitch & Roll:** Standard trigonometric calculations provide a full picture of your posture.

- **Dynamic Web Dashboard:**  
  - Hosted on the ESP8266, the dashboard updates automatically (every 500ms) with live sensor data.
  
- **Modular & Expandable Design:**  
  - Ready for future enhancements like mobile notifications or AI-based posture analysis.

---

## System Architecture

      +-----------------------+
      |   MPU6050 Sensor      |
      | (Accelerometer,       |
      |  Gyroscope, Temp)     |
      +-----------+-----------+
                  |
                  | I2C Communication
                  |
      +-----------v-----------+
      | ESP8266 Microcontroller|
      | (Data Acquisition,      |
      |  Processing, Wi-Fi)     |
      +-----------+-----------+
                  |
                  | HTTP/AJAX Communication
                  |
      +-----------v-----------+
      |   Wi-Fi Network       |
      | (ESP8266 Access Point)|
      +-----------+-----------+
                  |
                  | Real-Time Data
                  |
      +-----------v-----------+
      | Mobile/Web Client     |
      | (Dashboard Interface) |
      +-----------------------+


---

## Tech Stack

- **Hardware:**  
  - **ESP8266 Microcontroller:** Provides Wi-Fi connectivity and sufficient processing power.
  - **MPU6050 Sensor:** 3-axis accelerometer, gyroscope, and temperature sensor.

- **Firmware / Embedded Software:**  
  - **Arduino (C++):** Developed using the Arduino IDE.
  - **Libraries:**  
    - ESP8266WiFi, ESP8266WebServer  
    - Adafruit MPU6050, Adafruit Sensor  
    - math.h for trigonometric calculations

- **Web Dashboard:**  
  - **Frontend:** HTML, CSS, JavaScript
  - **AJAX:** For real-time, auto-updating sensor data

- **Version Control:**  
  - **Git & GitHub:** Repository hosted at [PostureGuard](https://github.com/Sidd-Patel/PostureGuard)

---

## Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Sidd-Patel/PostureGuard.git
   cd PostureGuard
Install Dependencies:

Ensure you have the Arduino IDE installed.
Install the following libraries via the Arduino Library Manager:
ESP8266WiFi
ESP8266WebServer
Adafruit MPU6050
Adafruit Sensor
Upload Firmware:

Open the main .ino file in the Arduino IDE.
Select your ESP8266 board (e.g., NodeMCU).
Upload the code.
Hardware Setup:

Connect the MPU6050 sensor to the ESP8266 as per the wiring diagram (refer to documentation if available).
Power up the system; the ESP8266 will automatically start in Access Point mode.
Usage
Connect to Wi-Fi:

On your mobile device or computer, connect to the Wi-Fi network:
SSID: Hackdata
Password: 12345678
Access the Dashboard:

Open your web browser and navigate to http://192.168.4.1.
View real-time sensor data, including Posture Angle, Pitch, and Roll. The dashboard refreshes automatically every 500ms.
Contributing
Contributions are welcome! If you have suggestions or improvements:

Fork the repository and create a pull request.
For major changes, please open an issue first to discuss your ideas.
Check out the CONTRIBUTING.md file for detailed guidelines.
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgements
Hackdata 2025: For inspiring innovative solutions in healthcare.
Adafruit: For their excellent sensor libraries.

# PostureGuard

*Your Smart Posture Guardian for a Healthier Life*

---

## 📋 Overview

PostureGuard is an intelligent, real-time posture monitoring system that helps you maintain proper posture whether you're at your desk or on the move. Leveraging wearable sensor technology and a dynamic web dashboard, PostureGuard provides instant feedback to correct your posture and prevent long-term musculoskeletal issues.

---

## ✨ Key Features

- **Dual-Mode Operation:**
  - **Normal Mode:** Strict monitoring for sedentary activities.
  - **Activity Mode:** Flexible monitoring during physical activity to avoid false alerts.
- **Intelligent Detection:**
  - Differentiates between intentional movements and poor posture using advanced filtering algorithms.
  - Tracks the duration of poor posture and provides timely corrective feedback.
- **Personalized Calibration:**
  - Quick calibration to your ideal posture baseline.
  - Customizable sensitivity thresholds for a tailored experience.
- **Real-Time Data Visualization:**
  - Live tracking of posture angle, pitch, roll, accelerometer, and gyroscope data.
  - Auto-updating web dashboard accessible from any Wi-Fi enabled device.

---

## 🖥️ System Architecture

![System Architecture Diagram](https://github.com/Sidd-Patel/PostureGuard/blob/f82f2892e5d70745c76835d27f74d368d55333c1/System%20Architecture%20Diagram.png)

*Figure: System Architecture of PostureGuard*
              +-----------------------+
              |    MPU6050 Sensor     |
              | (Accelerometer,       |
              |  Gyroscope, Temp)     |
              +-----------+-----------+
                            |
                            | I2C Communication
                            |
              +-----------v-----------+
              | ESP8266 Microcontroller|
              | (Data Acquisition,     |
              |  Processing, Wi-Fi)    |
              +-----------+-----------+
                            |
                            | HTTP/AJAX Communication
                            |
              +-----------v-----------+
              |    Wi-Fi Network      |
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

## 🛠️ Tech Stack

- **Hardware:**
  - **ESP8266 Microcontroller:** Provides Wi-Fi connectivity and processing power.
  - **MPU6050 Sensor:** 3-axis accelerometer, gyroscope, and temperature sensor.
- **Firmware / Embedded Software:**
  - **Arduino (C++):** Developed using the Arduino IDE.
  - **Libraries:**
    - ESP8266WiFi, ESP8266WebServer
    - Adafruit MPU6050, Adafruit Sensor
    - math.h for trigonometric calculations.
- **Web Dashboard:**
  - **Frontend:** HTML, CSS, JavaScript with AJAX for real-time updates.
- **Version Control:**
  - **Git & GitHub:** Repository hosted at [PostureGuard](https://github.com/Sidd-Patel/PostureGuard)

---

## 🚀 Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or later)
- Compatible sensor hardware (ESP8266, MPU6050)
- Modern web browser
- USB cable for ESP8266 connection to your computer.

### Installation

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/Sidd-Patel/PostureGuard.git](https://github.com/Sidd-Patel/PostureGuard.git)
    cd PostureGuard
    ```
2.  **Install Dependencies (Arduino Libraries):**
    - Open the Arduino IDE.
    - Go to Sketch > Include Library > Manage Libraries...
    - Search for and install the following libraries:
      - ESP8266WiFi by ESP8266 Community
      - ESP8266WebServer by ESP8266 Community
      - Adafruit MPU6050 Library by Adafruit
      - Adafruit Unified Sensor Library by Adafruit
    - Close the Library Manager.
3.  **Hardware Setup:**
    - Connect the MPU6050 sensor to the ESP8266 according to the wiring diagram provided in the documentation (or within the .ino file comments).
    - Common connections include:
      - MPU6050 VCC to ESP8266 3.3V
      - MPU6050 GND to ESP8266 GND
      - MPU6050 SDA to ESP8266 D2 (or SDA pin)
      - MPU6050 SCL to ESP8266 D1 (or SCL pin)
4.  **Upload Firmware:**
    - Open the PostureGuard.ino file in the Arduino IDE.
    - Go to Tools > Board > ESP8266 Boards (e.g., NodeMCU 1.0 (ESP-12E Module)).
    - Go to Tools > Port and select the COM port (Windows) or /dev/tty.* (macOS/Linux) corresponding to your ESP8266.
    - Click the Upload button (right arrow) to flash the code to your ESP8266.
    - Wait for the upload to complete.
5.  **Connect to the ESP8266 Access Point:**
    - After the ESP8266 restarts, it will create a Wi-Fi access point.
    - Use a Wi-Fi-enabled device (computer, smartphone) to connect to the network named "PostureGuardAP" (or whatever name you set in the .ino file).
    - Open a web browser and navigate to 192.168.4.1 (the default IP address of the ESP8266 access point).
6.  **Access the Dashboard:**
    - The PostureGuard web dashboard should load in your browser, displaying real-time sensor data.

---

## 📊 Dashboard Overview

- **Real-Time Data Visualization:** Live display of posture angle, pitch, roll, accelerometer, and gyroscope readings.
- **Interactive Interface:** Auto-refreshing dashboard (updates every 500ms) accessible via any Wi-Fi enabled device.

---

## 🔧 Usage Tips

- **Calibration:** For optimal results, calibrate the system while maintaining your ideal posture. Follow the on-screen instructions to calibrate smoothly.
- **Mode Switching:** Use "Normal Mode" for desk work and "Activity Mode" during physical exercises to avoid false alerts.
- **Threshold Adjustments:** Customize sensitivity thresholds to suit your comfort and requirements.
- **Mobile Integration:** The dashboard features a responsive design, ensuring seamless access and monitoring on desktops, tablets, and smartphones. Connect to the ESP8266 Access Point and monitor your posture in real time via your browser.

---

## 🔍 How It Works

1.  **Sensor Data Collection:** The MPU6050 sensor continuously gathers data.
2.  **Data Processing:** The ESP8266 computes posture angle (using custom Z-axis remapping), pitch, and roll using advanced algorithms.
3.  **Smart Filtering:** The system differentiates between poor posture and intentional movement using filtering algorithms.
4.  **Real-Time Feedback:** AJAX is used to update the dashboard every 500ms, providing instant feedback.

---

## 🔄 Future Enhancements

- Integration of machine learning for enhanced activity recognition.
- Detailed long-term posture analytics.
- Integration with fitness and health tracking platforms.
- Customizable alert sounds and vibration patterns.
- Cloud synchronization for multi-device usage.

---

## 📝 License

This project is licensed under the MIT License - see the `LICENSE` file for details.

---

## 👥 Contributing

Contributions are welcome! If you have suggestions or improvements:

- Fork the repository and create a pull request.
- For major changes, please open an issue first to discuss your ideas.
- See `CONTRIBUTING.md` for detailed guidelines.

---

## 💬 Contact & Support

- **Developer:** Sidd Patel
- **Report Issues:** [GitHub Issues](https://github.com/Sidd-Patel/PostureGuard/issues)
- **Website:** Coming Soon

Your journey to better posture and a healthier life begins with PostureGuard!

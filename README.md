# PostureGuard  
*Your Smart Posture Guardian for a Healthier Life*  

---

📋 **Overview**  
PostureGuard is an intelligent, real-time posture monitoring system that helps you maintain proper posture whether you're at your desk or on the move. Leveraging wearable sensor technology and a dynamic web dashboard, PostureGuard provides instant feedback to correct your posture and prevent long-term musculoskeletal issues.

---

✨ **Key Features**  
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

🖥️ **System Architecture**  
![System Architecture Diagram](https://github.com/Sidd-Patel/PostureGuard/blob/f82f2892e5d70745c76835d27f74d368d55333c1/System%20Architecture%20Diagram.png)
*Figure: System Architecture of PostureGuard*  

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

🛠️ **Tech Stack**  
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

🚀 **Getting Started**

### Prerequisites  
- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or later)  
- Compatible sensor hardware (ESP8266, MPU6050)  
- Modern web browser

### Installation

```bash
# 1. Clone the Repository:
git clone https://github.com/Sidd-Patel/PostureGuard.git
cd PostureGuard

# 2. Install Dependencies:
 Open the Arduino IDE and install the following libraries via the Library Manager:
 - ESP8266WiFi
 - ESP8266WebServer
 - Adafruit MPU6050
 - Adafruit Sensor

# 3. Upload Firmware:
 - Open the main .ino file in the Arduino IDE.
 - Select your ESP8266 board (e.g., NodeMCU).
 - Upload the code to your device.

# 4. Hardware Setup:
 - Connect the MPU6050 sensor to the ESP8266 as per the wiring diagram provided in the docs.
 - Power up the system; the ESP8266 will automatically start in Access Point mode.

---

📊 **Dashboard Overview**

Real-Time Data Visualization:
Live display of posture angle, pitch, roll, accelerometer, and gyroscope readings.
Interactive Interface:
Auto-refreshing dashboard (updates every 500ms) accessible via any Wi-Fi enabled device.
---


📊 **Dashboard Overview**

Real-Time Data Visualization:
Live display of posture angle, pitch, roll, accelerometer, and gyroscope readings.
Interactive Interface:
Auto-refreshing dashboard (updates every 500ms) accessible via any Wi-Fi enabled device.
🔧 Usage Tips

Calibration:
For optimal results, calibrate the system while maintaining your ideal posture.
Follow the on-screen instructions to calibrate smoothly.
Mode Switching:
Use Normal Mode for desk work and Activity Mode during physical exercises.
Threshold Adjustments:
Customize sensitivity thresholds to suit your comfort and requirements.
📱 Mobile Integration

Enjoy a responsive design that works seamlessly on desktops, tablets, and smartphones.
Connect to the ESP8266 Access Point and monitor your posture in real time via your browser.
🔍 How It Works

Sensor Data Collection: Continuously gathers data from the MPU6050 sensor.
Data Processing: Computes posture angle (using custom Z-axis remapping), pitch, and roll using advanced algorithms.
Smart Filtering: Differentiates between poor posture and intentional movement.
Real-Time Feedback: Uses AJAX to update the dashboard every 500ms.
🔄 Future Enhancements

Integration of machine learning for enhanced activity recognition.
Detailed long-term posture analytics.
Integration with fitness and health tracking platforms.
Customizable alert sounds and vibration patterns.
Cloud synchronization for multi-device usage.
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

👥 Contributing
Contributions are welcome! If you have suggestions or improvements:

Fork the repository and create a pull request.
For major changes, please open an issue first to discuss your ideas.
See CONTRIBUTING.md for detailed guidelines.
💬 Contact & Support

Developer: Sidd Patel
Report Issues: GitHub Issues
Website: Coming Soon
Your journey to better posture and a healthier life begins with PostureGuard!

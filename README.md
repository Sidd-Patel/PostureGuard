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
![System Architecture Diagram](images/System Architecture Diagram.png)  
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
# Open the Arduino IDE and install the following libraries via the Library Manager:
# - ESP8266WiFi
# - ESP8266WebServer
# - Adafruit MPU6050
# - Adafruit Sensor

# 3. Upload Firmware:
# - Open the main .ino file in the Arduino IDE.
# - Select your ESP8266 board (e.g., NodeMCU).
# - Upload the code to your device.

# 4. Hardware Setup:
# - Connect the MPU6050 sensor to the ESP8266 as per the wiring diagram provided in the docs.
# - Power up the system; the ESP8266 will automatically start in Access Point mode.

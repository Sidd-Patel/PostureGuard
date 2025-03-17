# PostureGuard  
*An innovative smart posture tracking system that protects your health in real time*  

---

📋 **Overview**  
PostureGuard is a cutting-edge posture monitoring system that uses wearable sensor technology and a dynamic web dashboard to help you maintain proper posture—whether you're at your desk or on the move. It intelligently distinguishes between intentional movements and poor posture, providing immediate, actionable feedback to prevent musculoskeletal issues.

---

✨ **Key Features**  
- **Dual-Mode Operation:**  
  - **Normal Mode:** Strict monitoring for sedentary activities.  
  - **Activity Mode:** Flexible monitoring during physical activities to avoid false alerts.
- **Intelligent Detection:**  
  - Differentiates between intentional movements and poor posture.  
  - Tracks the duration of poor posture for timely corrective feedback.
- **Personalized Calibration:**  
  - Quickly calibrate to your ideal posture baseline.  
  - Customizable sensitivity thresholds for a tailored experience.
- **Real-Time Data Visualization:**  
  - Live tracking of posture angle, pitch, roll, accelerometer, and gyroscope data.  
  - Interactive dashboard with historical trend analysis.

---

🖥️ **Technical Details**  
- **Built With:**  
  - **Firmware:** Arduino (C++) running on an ESP8266  
  - **Web Dashboard:** HTML, CSS, and JavaScript (AJAX for real-time updates)  
  - **Sensor Integration:** MPU6050 (accelerometer, gyroscope, and temperature sensor)
- **Key Algorithms:**  
  - Calculation of Posture Angle using Z-axis remapping (i.e., -9.8 m/s² → +90°, 9.8 m/s² → -90°)  
  - Computation of Pitch & Roll using trigonometric formulas  
  - Smart filtering to differentiate between poor posture and exercise

---

🚀 **Getting Started**

### Prerequisites  
- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or later)  
- Compatible sensor hardware (ESP8266, MPU6050)  
- Modern web browser

### Installation

```bash
# 1. Clone the repository:
git clone https://github.com/Sidd-Patel/PostureGuard.git
cd PostureGuard

# 2. Install Dependencies:
# - Open the Arduino IDE and install the following libraries via the Library Manager:
#   - ESP8266WiFi
#   - ESP8266WebServer
#   - Adafruit MPU6050
#   - Adafruit Sensor

# 3. Upload Firmware:
# - Open the main .ino file in the Arduino IDE.
# - Select your ESP8266 board (e.g., NodeMCU).
# - Upload the code to your device.

# 4. Hardware Setup:
# - Connect the MPU6050 sensor to the ESP8266 as per the wiring diagram provided in the docs.
# - Power up the system; the ESP8266 will automatically start in Access Point mode.


📊 Dashboard Overview

Real-Time Data Visualization:
Live display of posture angle, pitch, roll, accelerometer, and gyroscope readings.
Interactive Interface:
Auto-refreshing dashboard (updates every 500ms) accessible from any Wi-Fi enabled device.
🔧 Usage Tips

Calibration:
For optimal results, calibrate the system while maintaining your ideal posture.
Follow on-screen instructions for a smooth calibration process.
Mode Switching:
Use Normal Mode for desk work.
Switch to Activity Mode during physical exercises to adjust sensitivity.
📱 Mobile Integration

Enjoy a responsive design that works seamlessly on desktops, tablets, and smartphones.
Connect to the ESP8266 Access Point and monitor your posture in real time via your browser.
🔍 How It Works

Sensor Data Collection: Continuously gathers data from the MPU6050 sensor.
Data Processing: Computes posture angle, pitch, and roll using advanced algorithms.
Smart Filtering: Differentiates between poor posture and intentional movement.
Real-Time Feedback: Updates the dashboard using AJAX for a seamless user experience.
🔄 Future Enhancements

Integration of machine learning for enhanced activity recognition.
Detailed long-term posture analytics.
Integration with fitness and health tracking platforms.
Customizable alert sounds and vibration patterns.
Cloud synchronization for multi-device usage.
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

👥 Contact & Support

Developer: Sidd Patel
Report Issues: GitHub Issues
Website: Coming Soon
Your journey to better posture and a healthier life begins with PostureGuard!

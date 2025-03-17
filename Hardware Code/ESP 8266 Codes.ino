#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <math.h>  // For asin(), atan2(), and PI

// Wi-Fi Credentials for the Access Point
const char* ssid = "(2)Hackdata_32";
const char* password = "12345678";

// Create a web server on port 80
ESP8266WebServer server(80);
Adafruit_MPU6050 mpu;

// This function handles the /data route and sends sensor data as JSON
void handleData() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // Calculate Posture Angle using Z-axis:
  // Remap rule: Z = -9.8 m/s² => +90°, Z = 9.8 m/s² => -90°
  float ratio = a.acceleration.z / 9.81;
  if (ratio > 1.0) ratio = 1.0;
  if (ratio < -1.0) ratio = -1.0;
  float postureAngle = -asin(ratio) * 180.0 / PI;
  
  // Calculate Pitch and Roll using standard formulas:
  float pitchAngle = atan2(-a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180.0 / PI;
  float rollAngle  = atan2(a.acceleration.y, a.acceleration.z) * 180.0 / PI;
  
  // === Single Change: Print sensor data in a normal, formatted style to Serial Monitor ===
  Serial.println("----- Sensor Data -----");
  Serial.print("Accelerometer (m/s^2): X = ");
  Serial.print(a.acceleration.x, 2);
  Serial.print(", Y = ");
  Serial.print(a.acceleration.y, 2);
  Serial.print(", Z = ");
  Serial.println(a.acceleration.z, 2);
  
  Serial.print("Gyroscope (°/s): X = ");
  Serial.print(g.gyro.x, 2);
  Serial.print(", Y = ");
  Serial.print(g.gyro.y, 2);
  Serial.print(", Z = ");
  Serial.println(g.gyro.z, 2);
  
  Serial.print("Temperature (°C): ");
  Serial.println(temp.temperature, 2);
  
  Serial.print("Posture Angle (°): ");
  Serial.println(postureAngle, 2);
  
  Serial.print("Pitch Angle (°): ");
  Serial.println(pitchAngle, 2);
  
  Serial.print("Roll Angle (°): ");
  Serial.println(rollAngle, 2);
  Serial.println("-----------------------");
  
  // Build a JSON string with all sensor values and angles for the web response
  String json = "{";
  json += "\"ax\":" + String(a.acceleration.x, 2) + ",";
  json += "\"ay\":" + String(a.acceleration.y, 2) + ",";
  json += "\"az\":" + String(a.acceleration.z, 2) + ",";
  json += "\"gx\":" + String(g.gyro.x, 2) + ",";
  json += "\"gy\":" + String(g.gyro.y, 2) + ",";
  json += "\"gz\":" + String(g.gyro.z, 2) + ",";
  json += "\"temperature\":" + String(temp.temperature, 2) + ",";
  json += "\"postureAngle\":" + String(postureAngle, 2) + ",";
  json += "\"pitchAngle\":" + String(pitchAngle, 2) + ",";
  json += "\"rollAngle\":" + String(rollAngle, 2);
  json += "}";
  
  server.send(200, "application/json", json);
}

// This function handles the root URL and serves an HTML page that auto-updates using AJAX
void handleRoot() {
  String html = "<html><head>";
  html += "<title>ESP8266 Sensor Data</title>";
  html += "<script>";
  html += "function updateData() {";
  html += "fetch('/data').then(response => response.json()).then(data => {";
  html += "document.getElementById('ax').innerText = data.ax;";
  html += "document.getElementById('ay').innerText = data.ay;";
  html += "document.getElementById('az').innerText = data.az;";
  html += "document.getElementById('gx').innerText = data.gx;";
  html += "document.getElementById('gy').innerText = data.gy;";
  html += "document.getElementById('gz').innerText = data.gz;";
  html += "document.getElementById('temp').innerText = data.temperature;";
  html += "document.getElementById('posture').innerText = data.postureAngle;";
  html += "document.getElementById('pitch').innerText = data.pitchAngle;";
  html += "document.getElementById('roll').innerText = data.rollAngle;";
  html += "});";
  html += "}";
  html += "setInterval(updateData, 500);"; // Auto-update every 500ms
  html += "</script></head><body onload='updateData()'>";
  html += "<h1>ESP8266 Sensor Data</h1>";
  html += "<p>Accelerometer (m/s²): X=<span id='ax'></span>, Y=<span id='ay'></span>, Z=<span id='az'></span></p>";
  html += "<p>Gyroscope (°/s): X=<span id='gx'></span>, Y=<span id='gy'></span>, Z=<span id='gz'></span></p>";
  html += "<p>Temperature (°C): <span id='temp'></span></p>";
  html += "<p>Posture Angle (°) [Z-axis mapping]: <span id='posture'></span></p>";
  html += "<p>Pitch Angle (°): <span id='pitch'></span></p>";
  html += "<p>Roll Angle (°): <span id='roll'></span></p>";
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(4, 5);  // SDA = D2 (GPIO4), SCL = D1 (GPIO5)
  
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }
  Serial.println("MPU6050 Initialized!");
  
  // Set up the ESP8266 as a Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());
  
  // Define URL routes
  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

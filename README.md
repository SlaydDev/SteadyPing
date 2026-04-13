# SteadyPing 📡

![Arduino Registry](https://img.shields.io/badge/Arduino-Library-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/SlaydDev/SteadyPing?style=for-the-badge&color=blue)
![License](https://img.shields.io/github/license/SlaydDev/SteadyPing?style=for-the-badge&color=orange)
![Maintained](https://img.shields.io/badge/Maintained%3F-yes-green.svg?style=for-the-badge)

**SteadyPing** is a high-stability Arduino library developed by **Slayd Development** to solve the "jitter" problem common with HC-SR04 ultrasonic sensors. 

While standard code often produces jumpy, unstable readings (e.g., 25.1, 26.4, 24.8), **SteadyPing** uses signal processing techniques to deliver a rock-solid, single-decimal output.

## ✨ Features
- **Median Filter:** Collects a burst of 5 samples and selects the middle value to ignore random interference or "ghost" pings.
- **Precision Rounding:** Automatically formats data to one decimal place (e.g., `27.7 cm`) for professional Serial display.
- **Micro-Delay Timing:** Optimized `pulseIn` timeouts to prevent code "hangs" when no object is detected.
- **Universal Compatibility:** Designed to run efficiently on Arduino Uno, Mega, Nano, and ESP-series boards.

## 🚀 Installation

### Via Arduino Library Manager (Recommended)
1. Open the Arduino IDE.
2. Go to **Sketch** -> **Include Library** -> **Manage Libraries...**
3. Search for **SteadyPing** and click **Install**.

### Manual Installation
1. Download the latest release as a `.zip`.
2. In the Arduino IDE, go to **Sketch** -> **Include Library** -> **Add .ZIP Library...**
3. Select the downloaded file.

## 🛠️ Quick Start
```cpp
#include <SteadyPing.h>

// Initialize: SteadyPing objectName(TrigPin, EchoPin);
SteadyPing sonar(9, 10); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get a stable, rounded reading in one line
  float distance = sonar.getDistance(); 
  
  Serial.print("Stable Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}
```
## 🔧 Engineering Logic
SteadyPing doesn't just average numbers (which can still be skewed by huge errors). It implements a Bubble Sort algorithm on the sensor buffer to find the mathematical median. This ensures that even if the sensor triggers a "zero" or "infinity" reading by mistake, your project stays steady.

Maintainer: CaptainEXE

Organization: [Slayd Development](https://slayddev.vercel.app)

Status: v1.0.0-Stable

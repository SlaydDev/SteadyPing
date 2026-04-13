/* * SteadyPing - LED Distance Alert
 * --------------------------------------------------
 * Created by Captain.EXE | Slayd Development
 * Official Arduino Library for Stable Ultrasonic Sensing
 * * Website: https://slayddev.vercel.app
 * GitHub:  https://github.com/SlaydDev/SteadyPing
 * --------------------------------------------------
 */

#include <SteadyPing.h>

SteadyPing sonar(9, 10);
const int ledPin = 13; // Built-in LED

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  float dist = sonar.getDistance();

  // LED turns on if an object is closer than 15cm
  if (dist > 0 && dist < 15.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(50);
}

/* * SteadyPing - Basic Serial Readout
 * --------------------------------------------------
 * Created by Captain.EXE | Slayd Development
 * Official Arduino Library for Stable Ultrasonic Sensing
 * * Website: https://slayddev.vercel.app
 * GitHub:  https://github.com/SlaydDev/SteadyPing
 * --------------------------------------------------
 */

#include <SteadyPing.h>

SteadyPing sonar(9, 10); // Trig Pin 9, Echo Pin 10

void setup() {
  Serial.begin(9600);
  Serial.println("SteadyPing System Online...");
}

void loop() {
  float distance = sonar.getDistance();
  
  Serial.print("Stable Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}

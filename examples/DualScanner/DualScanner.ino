/* * SteadyPing - Dual Sensor Array
 * --------------------------------------------------
 * Created by Captain.EXE | Slayd Development
 * Official Arduino Library for Stable Ultrasonic Sensing
 * * Website: https://slayddev.vercel.app
 * GitHub:  https://github.com/SlaydDev/SteadyPing
 * --------------------------------------------------
 */

#include <SteadyPing.h>

SteadyPing leftSensor(2, 3);
SteadyPing rightSensor(4, 5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float L = leftSensor.getDistance();
  float R = rightSensor.getDistance();

  Serial.print("L: "); Serial.print(L);
  Serial.print(" | R: "); Serial.println(R);

  if (L < 10.0 || R < 10.0) {
    Serial.println("WARNING: Obstacle Detected!");
  }

  delay(100);
}

/* * SteadyPing - Distance Tone Generator
 * --------------------------------------------------
 * Created by Captain.EXE | Slayd Development
 * Official Arduino Library for Stable Ultrasonic Sensing
 * * Website: https://slayddev.vercel.app
 * GitHub:  https://github.com/SlaydDev/SteadyPing
 * --------------------------------------------------
 */

#include <SteadyPing.h>

SteadyPing sonar(9, 10);
const int buzzerPin = 8;

void setup() {}

void loop() {
  float dist = sonar.getDistance();

  if (dist > 0 && dist < 40) {
    // Pitch goes up as the object gets closer
    int pitch = map(dist, 2, 40, 1200, 300);
    tone(buzzerPin, pitch);
  } else {
    noTone(buzzerPin);
  }
  
  delay(40);
}

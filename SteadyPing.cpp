#include "SteadyPing.h"

SteadyPing::SteadyPing(int trigPin, int echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  _trig = trigPin;
  _echo = echoPin;
}

float SteadyPing::_getPing() {
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);
  
  // Timeout at 30ms (approx 5 meters)
  long duration = pulseIn(_echo, HIGH, 30000); 
  if (duration == 0) return 999.0; // Return high value if no echo
  return (duration * 0.0343) / 2.0;
}

float SteadyPing::getDistance() {
  float samples[5];
  
  // Collect 5 samples
  for(int i = 0; i < 5; i++) {
    samples[i] = _getPing();
    delay(10); 
  }

  // Sort samples (Bubble Sort) to find the median
  for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 5; j++) {
      if(samples[i] > samples[j]) {
        float temp = samples[i];
        samples[i] = samples[j];
        samples[j] = temp;
      }
    }
  }

  // Pick the middle value (Median) to avoid "jitter" spikes
  float median = samples[2];

  // Round to 1 decimal place (e.g., 27.7)
  return round(median * 10.0) / 10.0;
}
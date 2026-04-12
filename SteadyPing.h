#ifndef SteadyPing_h
#define SteadyPing_h

#include "Arduino.h"

class SteadyPing {
  public:
    // Constructor: Define your Trigger and Echo pins
    SteadyPing(int trigPin, int echoPin); 
    
    // Returns distance rounded to 1 decimal place (e.g., 27.7)
    float getDistance(); 

  private:
    int _trig;
    int _echo;
    float _getPing(); // Internal raw measurement
};

#endif
#ifndef AngleSensor_h
#define AngleSensor_h

#include <Arduino.h>
#include "Task.h"
#include "Sensor.h"

class AngleSensor: public Task, public Sensor<float> {
  public:
    AngleSensor(int pin, int voltage, unsigned int interval);
   private:
   void Init();
    void Callback();
    int _voltage;
    int _inputPin;
};

#endif

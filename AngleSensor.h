#ifndef AngleSensor_h
#define AngleSensor_h

#include <Arduino.h>
#include "Task.h"

class AngleSensor: public Task {
  public:
    AngleSensor(int pin, int voltage, unsigned int interval);
    float GetValue();
    bool ValueChanged();
   private:
    void Init();
    void Callback();
    int _voltage;
    int _inputPin;
    float _degrees;
    float _previousValue;
};

#endif

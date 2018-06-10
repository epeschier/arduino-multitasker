#ifndef Button_h
#define Button_h

#include <Arduino.h>

#include "Task.h"
#include "Sensor.h"

class Button: public Task, public Sensor<bool> {
   public:
    Button(int pin, unsigned int interval);
   private:
    void Init();
    void Callback();
    int _inputPin;
};

#endif

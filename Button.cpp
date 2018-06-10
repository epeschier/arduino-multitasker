#include "Button.h"

Button::Button(int pin, unsigned int interval) : Task(interval), Sensor() {
  _inputPin = pin;
}

void Button::Init() {
  pinMode(_inputPin, INPUT);
}

void Button::Callback() {
  int sensor_value = digitalRead(_inputPin);
  _value = (sensor_value == HIGH);
}

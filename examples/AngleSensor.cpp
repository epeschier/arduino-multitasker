#include "AngleSensor.h"

#define FULL_ANGLE 300 // Full value of the rotary angle is 300 degrees.

AngleSensor::AngleSensor(int pin, int voltage, unsigned int interval) : Task(interval) , Sensor() {
  _inputPin = pin;
  _voltage = voltage;
  Init();
}

void AngleSensor::Init() {
  pinMode(_inputPin, INPUT);
}

void AngleSensor::Callback() {
  int sensor_value = analogRead(_inputPin);
  float voltage = (float)sensor_value * _voltage / 1023;
  _value = (voltage*FULL_ANGLE) / _voltage;
}

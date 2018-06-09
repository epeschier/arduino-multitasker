#include "AngleSensor.h"

#define FULL_ANGLE 300 // Full value of the rotary angle is 300 degrees.

AngleSensor::AngleSensor(int pin, int voltage, unsigned int interval) : Task(interval) {
  _inputPin = pin;
  _voltage = voltage;
}

void AngleSensor::Init() {
  pinMode(_inputPin, INPUT);
}

float AngleSensor::GetValue() {
  _previousValue = _degrees;
  return _degrees;
}

bool AngleSensor::ValueChanged() {
  return (_previousValue != _degrees);
}

void AngleSensor::Callback() {
  int sensor_value = analogRead(_inputPin);
  float voltage = (float)sensor_value * _voltage / 1023;
  _degrees = (voltage*FULL_ANGLE) / _voltage;
}

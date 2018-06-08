#include "Blinker.h"

Blinker::Blinker(int output, unsigned int interval) : Task(interval) {
  State = false;
  OutputPin = output;
  Init();
}

void Blinker::Init() {
  pinMode(OutputPin, OUTPUT);
}

void Blinker::Callback() {
  Serial.println("Blink");
  digitalWrite(OutputPin, State);
  State = !State;
}


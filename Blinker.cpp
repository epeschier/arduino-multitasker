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
  digitalWrite(OutputPin, State);
  State = !State;
}


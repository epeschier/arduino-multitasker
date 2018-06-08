#include "Task.h"

Task::Task(unsigned int interval) {
  _interval = interval;
  Enable();
}

void Task::Run() {
  if (IsEnabled() && TimePassed()) {
    lastTime = millis();
    Callback();
  }
}

void Task::Enable() {
  _enabled = true;
}

void Task::Disable() {
  _enabled = false;
}

bool Task::IsEnabled() {
  return _enabled;
}

bool Task::TimePassed() {
  unsigned long time = millis();
  return ((time - lastTime) >= _interval);
}


#ifndef Task_h
#define Task_h

#include <Arduino.h>

class Task {
  public:
    Task(unsigned int interval);
    void Run();
    void Enable();
    void Disable();
    bool IsEnabled();
    virtual void Callback(void) = 0;
  private:
    bool TimePassed();
    unsigned int _interval;
    unsigned int _duration;
    bool _enabled;
    unsigned long lastTime;
};

#endif

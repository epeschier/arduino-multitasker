#ifndef Blinker_h
#define Blinker_h

#include "Task.h"

class Blinker: public Task {
  public:
    Blinker(int output, unsigned int interval);
   private:
    void Init();
    void Callback();
    bool State;
    int OutputPin;
};

#endif

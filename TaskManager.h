#ifndef TaskManager_h
#define TaskManager_h

#include <Arduino.h>
#include "Task.h"

#define MAX_TASKS 15

class TaskManager {
  public:
    static TaskManager* GetInstance();
    void Add(Task* task);
    void Remove(Task* task);
    void ProcessTasks();
    void Clear();
  private:
    static TaskManager* instance;
    TaskManager();
    Task* task[MAX_TASKS];
};

#endif

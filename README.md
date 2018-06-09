# Arduino Multitasker
Multitasking for Arduino.

# TaskManager
The Task Manager is a singleton object that will run all tasks.

# Task
Task is an abstract class which is used to implement specific tasks. Tasks are then added to the TaskManager for execution.

The `CallBack()` method implements the actual task.

Do not use `delay()` calls in your tasks as they will block execution!

# Example
First, create a TaskManager object. Then add specific tasks. Finally Call the ProcessTasks method from the TaskManager in a loop.

```cpp
TaskManager *taskManager;

void Setup() {
    taskManager = TaskManager::GetInstance();
    Blinker* b = new Blinker(LED, 1000);
    taskManager->Add(b);
}

void loop() {
  taskManager->ProcessTasks();
}
```

# Arduino Multitasker
Multitasking for Arduino.

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

# TaskManager
The `TaskManager` is a singleton object that will run all tasks.

Added tasks have to be a `Task` object.

TaskManager provides the following methods:
- `Add(Task*)`: add a task for scheduling.
- `Remove(Task*)`: remove task from the scheduler.
- `ProcessTasks()`: start processing all tasks. This shoud be called in the main loop of your sketch.
- `Clear()`: remove all tasks.

# Task
Task is an abstract class which is used to implement specific tasks. These Tasks can then added to the TaskManager for execution.

Task provides the following methods:
- `CallBack()`: implements the actual task.
- `Enable()`: enable task (default = enabled).
- `Disable()`: disable the task (task will be skipped by the Taskmanager).
- `IsEnabled()`: true if the task is enabled.
- `Run()`: run this task. Normally called by the `TaskManager`.

Do not use `delay()` calls in your tasks as they will block execution!

# Sensor

The `Sensor` class is an abstract templated class used for input sensors. Input can be of any type for example: bool, float or even an array of bytes read from an I2C port. The Sensor class is not needed for the multitasker but it is nice to have a generic class for reading input.

Sensor provides the following methods:
- `GetValue()`: reads the last state of the sensor.
- `ValueChanged()`: indicates if there was a change since the last time we read the value from the sensor.

A simple button would be declared like so:
```cpp
class Button: public Task, public Sensor<bool>
```

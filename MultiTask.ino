#include "TaskManager.h"
#include "Task.h"
#include "Blinker.h"
#include "AngleSensor.h"

/* Pin definitions */
#define LED 3
#define ROTARY_ANGLE_SENSOR A0
#define VCC 5

TaskManager* taskManager;

AngleSensor* angle;
Blinker* blinkingLed;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  taskManager = TaskManager::GetInstance();

  // Create Tasks
  blinkingLed = new Blinker(LED, 1000);
  angle = new AngleSensor(ROTARY_ANGLE_SENSOR, VCC, 200);
  
  // Add tasks to taskmanager.
  taskManager->Add(blinkingLed);
  taskManager->Add(angle);
}

void loop() {
  taskManager->ProcessTasks();
  delay(100);
  if (angle->ValueChanged()) {
    Serial.println(angle->GetValue());
  }
}

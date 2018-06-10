#include "TaskManager.h"
#include "Task.h"
#include "Blinker.h"
#include "AngleSensor.h"
#include "Button.h"

/* Pin definitions */
#define LED 3
#define BUTTON 2
#define ROTARY_ANGLE_SENSOR A0
#define VCC 5

TaskManager* taskManager;

AngleSensor* angle;
Blinker* blinkingLed;
Button* button;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  taskManager = TaskManager::GetInstance();

  // Create Tasks
  blinkingLed = new Blinker(LED, 1000);
  angle = new AngleSensor(ROTARY_ANGLE_SENSOR, VCC, 200);
  button = new Button(BUTTON, 100);
    
  // Add tasks to taskmanager.
  taskManager->Add(blinkingLed);
  taskManager->Add(angle);
  taskManager->Add(button);
}

void loop() {
  taskManager->ProcessTasks();
  delay(100);
  if (angle->ValueChanged()) {
    Serial.println(angle->GetValue());
  }
  if (button->ValueChanged()) {
    Serial.println(button->GetValue());
  }
}

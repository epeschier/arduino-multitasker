#include "TaskManager.h"
#include "Task.h"
#include "Blinker.h"

/* Pin definitions */
#define LED 3

TaskManager* taskManager;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  pinMode(BUTTON, INPUT);
  pinMode(RELAY, OUTPUT);

  taskManager = TaskManager::GetInstance();
  Blinker* b = new Blinker(LED, 1000);
  taskManager->Add(b);
}

void loop() {
  taskManager->ProcessTasks();
}

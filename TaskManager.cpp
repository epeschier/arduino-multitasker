#include "TaskManager.h"
#include "Task.h"

TaskManager* TaskManager::instance = 0;

TaskManager* TaskManager::GetInstance() {
  if (instance == 0) {
    instance = new TaskManager();  
  }
  return instance;
}

TaskManager::TaskManager() {
  Clear();
}

void TaskManager::Add(Task* t) {
  for(int i = 0; i < MAX_TASKS; i++){
    if(!task[i]){
      task[i] = t;
      return;
    }
  }
}

void TaskManager::Remove(Task* t) {
  for(int i = 0; i < MAX_TASKS; i++){
    if(task[i] == t){
      task[i] = NULL;
      return;
    }
  }
}

void TaskManager::ProcessTasks() {
  for(int i = 0; i < MAX_TASKS; i++){
    if(task[i]){
      task[i]->Run();
      return;
    }
  }
}

void TaskManager::Clear(){
  for(int i = 0; i < MAX_TASKS; i++){
    task[i] = NULL;
  }
}



#include <iostream>
#include <vector>
#include <algorithm>
#include "Headers.h"
using namespace std;


class User
{
private:
    char* _first_name;
    char* _last_name;
    int _age;
    vector<Task*> _tasks;

public:
    User(char* first_name, char* last_name, int age){
        this->_first_name = first_name;
        this->_last_name = last_name;
        this->_age = age;
        //this->_tasks = tasks;
    }

    //getters
    char* getFirstName(){
        return this->_first_name;
    }

    char* getLastName(){
        return this->_last_name;
    }
    
    int getAge(){
        return this->_age;
    }
    
    vector<Task*> getTasks(){
        return this->_tasks;
    }

    //setters
    void setFirstName(char *first_name){
        this->_first_name = first_name;
    }

    void setLastName(char* last_name){
        this->_last_name = last_name;
    }

    void setAge(int age){
        this->_age = age;
    }

    // void setTask(Task task, int pos){
    //     this->_tasks[pos] = task;
    // }

    //functions

    void addTask(Task* task){
        this->_tasks.push_back(task);
         sort(this->_tasks.begin(), this->_tasks.end(),
            [this](Task* t1, Task* t2) {
                return t1->getPriorityLevel() > t2->getPriorityLevel();
            });
    }

    void displayAllTasks(){
        if(this->_tasks.size() > 1)
            cout << "Hello, " << this->_first_name <<"! Your tasks are:\n";
        else
            cout << "Hello, " << this->_first_name<< "! Your task is:\n";

        for(int i = 0 ; i < this->_tasks.size(); i ++)
            cout << (i + 1) << "."  << this->_tasks[i]->getName() << "\n";
    
        cout << "\n";
    }

    bool customComparisonPriority(Task* t1, Task* t2){
        return t1->getPriorityLevel() > t2->getPriorityLevel();
    }

    void displayWorkTasks(){


        cout << "Hello, these are all of your work tasks (sorted by priority):\n";
        for(int i = 0; i < this->_tasks.size(); i ++)
            if (dynamic_cast<WorkTask*>(this->_tasks[i]))
            {
                cout << (i + 1) << "."  << this->_tasks[i]->getName() << "\n";
            }
            
    }

    
    void displayHomeTasks(){
        cout << "Hello, these are all of your home tasks (sorted by priority):\n";
        for(int i = 0; i < this->_tasks.size(); i ++)
            if (dynamic_cast<HomeTask*>(this->_tasks[i]))
            {
                cout << (i + 1) << "."  << this->_tasks[i]->getName() << "\n";
            }
            
    }

    void displayTaskDetails(Task* t1){
        cout << "Here is your task details: \n";
        cout << "Task Name: " << t1->getName() << "\n";
        cout << "Task Description: " << t1->getDescription() << "\n";
        cout << "Priority level: " << t1->getPriorityLevel() << "\n";
        if(t1->getCompleted() == 0)
            cout << "Task is NOT complete\n";
        else
            cout << "Task is complete\n";

    }


};



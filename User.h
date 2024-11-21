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


    void modifyTask(Task* task){
        cout << "Here is the details of you task: \n";
        cout << "Name of the task: " << task->getName() << "\n";
        cout << "Description of the task: " << task->getDescription() << "\n";
        cout << "Completion level of the task: " << task->getCompleted() << "\n";
        cout << "Priority level of the task: " << task->getPriorityLevel() << "\n";

        cout << "Do you want to modify anything? (y or n)\n";
        char answer;
        cin.get();
        cin >> answer;
        cin.get();

        if(answer == 'y'){
            cout << "What do you want to modify?\n";
            cout << "1. Name\n";
            cout << "2. Description\n";
            cout << "3. Completion level\n";
            cout << "4. Priority level\n";

            int choice;
            cin >> choice;

            if(choice == 1){
                cout << "\nEnter a new name: \n";
                char* task_name = new char[1024];
                cout << "Add task name: ";
                cin >>  task_name;
                cout << "\n";
                task->setTaskName(task_name);
            }

            if(choice == 2){
                cout << "\nEnter a new description: \n";
                char* task_description = new char[1024];
                cout << "Add task description: ";
                cin >>  task_description;
                cout << "\n";
                task->setDescription(task_description);

            }
            
            if(choice == 3){
                cout << "Is your task complete?(y or n)\n";
                char answer;
                cin.get();
                cin >> answer;
                cin.get();

                if(answer == 'y')
                    task->setCompleted(1);
                else
                    task->setCompleted(0);
            }
            
            if(choice == 4){
                cout << "\nEnter a new priority level: \n";
                int priority_level;
                cout << "Add priority level: ";
                cin >> priority_level;
                cout << "\n";
                task->setPriorityLevel(priority_level);
            }


        }
        
    }


};



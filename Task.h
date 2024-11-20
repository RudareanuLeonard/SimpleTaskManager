#include <iostream>
#include <string>
using namespace std;

class Task{
private:
    char* _task_name;
    char* _description;
    int _completed; //0 - not completed; 1 - completed
    int _priority_level;

public:
    Task(char* _task_name, char* _description, int completed, int priority_level){
        this->_task_name = _task_name;
        this->_description = _description;
        // cout << "Constructor created with values " << this->_task_name << " and " << this->_description ;
        this->_completed = completed;
        this->_priority_level = priority_level;
    }

    // virtual ~Task() { // Add this virtual destructor
    //     cout << "Task destructor called for " << _task_name << endl;
    // }
    //getters

    char* getName(){
        return this->_task_name;
    }

    char getDescription(){
        return *this->_description;
    }

    int getCompleted(){
        return this->_completed;
    }

    int getPriorityLevel(){
        return this->_priority_level;
    }

    //setters

    void setTaskName(char* task_name){
        this->_task_name = task_name;
    }

    void setDescription(char* description){
        this->_description = description;
    }

    void setCompleted(int completed){
        this->_completed = completed;
    }
    
    void setPriorityLevel(int priority_level){
        this->_priority_level = priority_level;
    }

    //virtual functions
    virtual void displayTaskDetails()=0;
};
#include <iostream>
#include "Headers.h"
using namespace std;

class HomeTask: public Task{

private:


public:
    using Task::Task;

    void displayTaskDetails(){
        cout << "Hello, this is a home task. Here are the details:\n";
        cout << "Task name: " << this->getName() << "\n";
        cout << "Task description: " << this->getDescription() << "\n";
        cout << "Task is: ";
        if(this->getCompleted() == 1)
            cout << "completed\n";
        else
            cout << "incomplete\n";
        cout << "Priority level: " << this->getPriorityLevel() << "\n";
    }


};
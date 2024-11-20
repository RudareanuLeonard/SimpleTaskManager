#include "Headers.h"
#include <iostream>
using namespace std;

class WorkTask: public Task{
private:

public:
    using Task::Task;
 void displayTaskDetails(){
        cout << "Hello, this is a work task. Here are the details:\n";
        cout << "Task name: " << this->getName() << "\n";
        cout << "Task description: " << this->getDescription() << "\n";
        cout << "Task is: ";
        if(this->getCompleted() == 1)
            cout << "completed\n";
        else
            cout << "incomplete\n";
        cout << "Priority level: " << this->getPriorityLevel() << "\n";
    }

   ~WorkTask() {
        cout << "WorkTask destructor called" << endl;
    }


};
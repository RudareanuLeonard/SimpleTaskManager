#include <iostream>
#include <memory>
#include <vector>

#include "Headers.h"

using namespace std;

int main(){

    WorkTask* t1 = new WorkTask("t1", "d1", 1, 1);
    WorkTask* t2 = new WorkTask("t2", "d2", 2, 20);

    User* u1 = new User("firstName", "secondName", 1);

    u1->addTask(t1);
    u1->addTask(t2);

    Task* t3 = new HomeTask("t3", "d3", 3, 2);
    u1->addTask(t3);
    u1->displayWorkTasks();

}
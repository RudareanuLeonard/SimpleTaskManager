#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Headers.h"

using namespace std;

const int BUFFER = 1024;

int main(){



    User* u1 = new User("Leo", "Rudareanu", 22);

    int run = 1;
    cout <<"Hello, " << u1->getFirstName() <<". Here are your options:\n";
    while(run){
        cout <<"0. Exit\n";
        cout << "1. Create a task\n";
        cout << "2. See all tasks\n";
        cout << "3. See Work Tasks\n";
        cout << "4. See Home Tasks\n";
        cout << "5. Edit a task\n";

        int choice;
        cin >> choice;
        while(choice > 5 or choice < 0){
            cout << "\n Enter a valid choice (0-5)\n";
            cin >> choice;
        }

        if(choice == 0)
            break;

        if(choice == 1){
            char* task_name = new char[BUFFER];
            cout << "Add task name: ";
            cin >>  task_name;
            cout << "\n";

            char* task_description = new char[BUFFER];
            cout << "Add task description: ";
            cin >>  task_description;
            cout << "\n";

            int completed = 0;

            int priority_level;
            cout << "Add priority level: ";
            cin >> priority_level;
            cout << "\n";

            
            cout << "Is this a Work Task or a Home Task? (home or work)";
            string work_home_task;
            cin >> work_home_task;
            if(work_home_task == "home"){
                HomeTask* task = new HomeTask(task_name, task_description, completed, priority_level);
                u1->addTask(task);
                
            }  
            else if (work_home_task == "work"){
                WorkTask* task = new WorkTask(task_name, task_description, completed, priority_level);
                u1->addTask(task);
            }
            else
                cout <<"Invalid\n";

        cout << "\n";
        }

        if(choice == 2)
            u1->displayAllTasks();
        
        if(choice == 3)
            u1->displayWorkTasks();
        
        if(choice == 4)
            u1->displayHomeTasks();

        if(choice == 5){
            u1->displayAllTasks();
            cout << "What task you want to modify(enter index): ";
            int task_to_modify;
            cin >> task_to_modify;
            while (task_to_modify > u1->getTasks().size())
            {   if(u1->getTasks().size() > 0)
                cout << "You should enter a smaller index... (1 - " << u1->getTasks().size() << ")\n";
                else{
                    cout << "You don't have any task\n\n";
                    break;
                }
            }

            Task* current_task = u1->getTasks()[task_to_modify - 1];

            u1->modifyTask(current_task);
            
        }


    }

}
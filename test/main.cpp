//
// Created by bender on 28/09/2025.
//

#include <iostream>

# include "Manager.hpp"


void Print()
{
    std::cout << "1: Add Task" << std::endl;
    std::cout << "2: Remove Task" << std::endl;
    std::cout << "3: Mark Completed" << std::endl;
    std::cout << "4: Show Tasks" << std::endl;
    std::cout << "5: Save and Exit" << std::endl;
}


int main()
{
    bool is_running = true;
    Manager list;

    while(is_running)
    {
        Print();

        char option = getchar();
        getchar();
        std::string description;
        size_t id;

        switch(option)
        {
        case '1':
            std::cout << "Enter the name of the task: ";
            std::getline(std::cin, description);
            list.Addtask(description);
            break;
        case '2':
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;
            list.Removetask(id);
            getchar();
            break;
        case '3':
            std::cout << "Enter task ID completed: ";
            std::cin >> id;
            list.Markcompleted(id);
            getchar();
            break;
        case '4':
            list.Listtasks();
            break;
        case '5':
            is_running = false;
            break;
        default:
            std::cout << "Please choose one of the valid options" << std::endl;
        }
    }


    return 0;
}
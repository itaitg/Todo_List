//
// Created by bender on 28/09/2025.
//

#include "Manager.hpp"

void Test()
{
    Manager man;

    man.Addtask("test1");
    man.Addtask("test2");
    man.Listtasks();

    // man.Markcompleted(1);
    // man.Markcompleted(2);
    //man.Addtask("");

    // man.Removetask(3);
    // man.Listtasks();
    // man.Addtask("test3");

}


int main()
{
 Test();

 return 0;
}
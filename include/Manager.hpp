//
// Created by bender on 28/09/2025.
//

#ifndef TODO_LIST_MANAGER_HPP
#define TODO_LIST_MANAGER_HPP

#include <vector>

#include "Task.hpp"

class Manager
{
public:
    Manager();
    ~Manager();

    void Addtask(const std::string& description);
    void Removetask(const size_t& id);
    void Markcompleted(const size_t& id);
    void Listtasks() const;


private:
    void Save();
    void Load();

    std::vector<Task> m_list;
    std::vector<Task> m_completed;
};



#endif //TODO_LIST_MANAGER_HPP
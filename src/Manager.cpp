//
// Created by bender on 28/09/2025.
//


#include <iostream>
#include <fstream>


#include "Manager.hpp"



Manager::Manager()
{
    Load();
}

Manager::~Manager()
{
    Save();
}

void Manager::Addtask(const std::string& description)
{
    if(description.empty())
    {
        std::cout << "description must be valid" << std::endl;
        return;
    }
    const Task temp(description);
    m_list.push_back(temp);
}

void Manager::Removetask(const size_t& id)
{
    auto iter = m_list.begin();

    while(iter != m_list.end())
    {
        if(iter->GetID() == id)
        {
           m_list.erase(iter);
            return;
        }
        ++iter;
    }
    std::cout << "ID: "<< id << " not found" << std::endl;
}

void Manager::Markcompleted(const size_t& id)
{
    auto iter = m_list.begin();

    while(iter != m_list.end())
    {
        if(iter->GetID() == id)
        {
            iter->Markcompleted();
            return;
        }
        ++iter;
    }
    std::cout << "ID: "<< id << " not found" << std::endl;
}

void Manager::Listtasks() const
{
    auto iter = m_list.begin();
    std::cout << "---------------TODO LIST----------------" << std::endl;
    while(iter != m_list.end())
    {
        std::string status;
        status = iter->Iscompleted() == true ? "Completed" : "To do";
        std::cout << "ID: " << iter->GetID();
        std::cout << ", " << iter->Getdesc();
        std::cout << ", status: " << status << std::endl;
        ++iter;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void Manager::Save()
{
    json j = m_list;
    std::ofstream file("test.json");
    file << j.dump(4); // pretty print with 4 spaces
}


void Manager::Load()
{
    {
        std::ifstream file("test.json");
        if (!file.is_open()) return;

        json j;
        file >> j;
        m_list = j.get<std::vector<Task>>();
    }
}

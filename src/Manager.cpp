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
{}

void Manager::Addtask(const std::string& description)
{
    if(description.empty())
    {
        std::cout << "description must be valid" << std::endl;
        return;
    }
    const Task temp(description);
    m_list.push_back(temp);
    Save();
}

void Manager::Removetask(const size_t& id)
{
    auto iter = m_list.begin();

    while(iter != m_list.end())
    {
        if(iter->GetID() == id)
        {
            m_list.erase(iter);
            Save();
            return;
        }
        ++iter;
    }
    iter = m_completed.begin();

    while(iter != m_completed.end())
    {
        if(iter->GetID() == id)
        {
            m_completed.erase(iter);
            Save();
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
            m_completed.emplace_back(*iter);
            m_list.erase(iter);
            Save();
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
        std::cout << "ID: " << iter->GetID();
        std::cout << ", " << iter->Getdesc() << std::endl;
        ++iter;
    }
    std::cout << "--------------COMPLETED-----------------" << std::endl;
    iter = m_completed.begin();
    while(iter != m_completed.end())
    {
        std::string status;
        std::cout << "ID: " << iter->GetID();
        std::cout << ", " << iter->Getdesc() << std::endl;
        ++iter;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void Manager::Save()
{
    json j;
    j["active"] = m_list;
    j["completed"] = m_completed;
    std::ofstream file("test.json");
    file << j.dump(4);
}


void Manager::Load()
{
    {
        std::ifstream file("test.json");
        if (!file.is_open()) return;

        json j;
        file >> j;

        if (j.contains("active"))   m_list = j["active"].get<std::vector<Task>>();
        if (j.contains("completed")) m_completed = j["completed"].get<std::vector<Task>>();
    }
}

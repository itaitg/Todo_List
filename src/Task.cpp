//
// Created by bender on 28/09/2025.
//

#include "Task.hpp"

Task::Task(const std::string& task): m_description(std::make_shared<std::string>(task)),
        m_completed(false)
{}

Task::Task(): m_id(0), m_description(std::make_shared<std::string>("")),
    m_completed(false)
{}

Task& Task::operator=(const Task& other)
{
    m_id = other.m_id;
    m_description = other.m_description;
    m_completed = other.m_completed;

    return *this;
}

std::string& Task::Getdesc() const
{
    return *m_description;
}

size_t Task::GetID() const
{
    return m_id.GetUID();
}

void Task::Markcompleted()
{
    m_completed = true;
}

bool Task::Iscompleted() const
{
    return m_completed;
}

void Task::Setdesc(const std::string& desc)
{
    m_description = std::make_shared<std::string>(desc);
}

void Task::SetID(size_t id)
{
    m_id.SetUID(id);
}

void Task::Setstatus(const bool status)
{
    m_completed = status;
}


void to_json(json& j, const Task& task)
{
    j = json
    {
            {"id", task.GetID()},
            {"description", task.Getdesc()},
            {"completed", task.Iscompleted()}
    };
}

void from_json(const json& j, Task& task)
{
    size_t id;
    j.at("id").get_to(id);
    task.SetID(id);

    std::string desc;
    j.at("description").get_to(desc);
    task.Setdesc(desc);

    bool status;
    j.at("completed").get_to(status);
    task.Setstatus(status);
}

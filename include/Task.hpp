//
// Created by bender on 28/09/2025.
//


#ifndef TODO_LIST_TASK_HPP
#define TODO_LIST_TASK_HPP

#include <memory>
#include <string>

#include "json.hpp"
#include "UID.hpp"

using json = nlohmann::json;


class Task
{
public:

    explicit Task(const std::string& task);
    Task();
    ~Task() = default;
    Task(const Task& other) = default;
    Task& operator=(const Task& other);


    std::string& Getdesc() const;
    size_t GetID() const;
    void Markcompleted();
    bool Iscompleted() const;

    void Setdesc(const std::string& desc);
    void SetID(size_t id);
    void Setstatus(bool status);

private:
    UID m_id;
    std::shared_ptr<std::string> m_description;
    bool m_completed;
};

void to_json(json& j, const Task& task);
void from_json(const json& j, Task& task);


#endif //TODO_LIST_TASK_HPP
//
// Created by bender on 28/09/2025.
//

#ifndef TODO_LIST_UID_HPP
#define TODO_LIST_UID_HPP

#include <cstddef>

class UID
{
public:
    UID();
    explicit UID(size_t opt);
    ~UID() = default;


    bool operator==(const UID& other) const;
    bool operator<(const UID& other) const;
    UID& operator=(const UID& other);

    size_t GetUID() const;
    void SetUID(size_t id);
    UID(const UID& other) = default;

private:
    static size_t m_counter;
    size_t m_id;
};

#endif //TODO_LIST_UID_HPP
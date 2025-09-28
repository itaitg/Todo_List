//
// Created by bender on 28/09/2025.
//


#include "UID.hpp"

size_t UID::m_counter = 1;

UID::UID(): m_id(m_counter++)
{}

UID::UID(const size_t opt): m_id(0)
{}

bool UID::operator==(const UID& other) const
{
    return m_id == other.m_id;
}

bool UID::operator<(const UID& other) const
{
    return m_id < other.m_id;
}

UID& UID::operator=(const UID& other)
{
    --m_counter;
    m_id = other.m_id;

    return *this;
}

size_t UID::GetUID() const
{
    return m_id;
}

void UID::SetUID(size_t id)
{
    m_id = id;
    m_counter = m_id >= m_counter ? m_id + 1 : m_counter;
}

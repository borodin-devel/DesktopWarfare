#pragma once

#include <string>

class Entity {
    friend class EntityManager;

public:
    ~Entity() = default;

    const size_t id() const { return m_id; }
    const std::string& tag() const { return m_tag; }
    bool isToBeDestroyed() const { return m_isToBeDestroyed; }
    void destroy() { m_isToBeDestroyed = true; }

protected:
    Entity(const size_t id, const std::string& tag)
        : m_id(id), m_tag(tag) {}

protected:
    const size_t m_id = 0;
    const std::string m_tag = "";
    bool m_isToBeDestroyed = false;
};
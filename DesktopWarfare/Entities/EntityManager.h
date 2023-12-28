#pragma once

#include <map>
#include <memory>
#include <vector>

#include "../Entities/Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
public:
    EntityManager() = default;

    void update();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& getEntities();
    EntityVec& getEntities(const std::string& tag);
 
private:
    EntityVec m_entities;
    EntityVec m_entitiesToAdd;
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;
};
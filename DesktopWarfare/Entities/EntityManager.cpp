#include "EntityManager.h"

void EntityManager::update()
{
    for (auto& e : m_entitiesToAdd) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }

    m_entitiesToAdd.clear();

    // Remove all entities from map and vector that are marked for deletion
    auto removeDestroyed = [](EntityVec& entities) {
        entities.erase(
            std::remove_if(
                entities.begin(),
                entities.end(),
                [](std::shared_ptr<Entity> e) {
                    return e->isToBeDestroyed();
                }),
            entities.end());
    };

    removeDestroyed(m_entities);

    for (auto& [tag, entityVec] : m_entityMap) {
        removeDestroyed(entityVec);
    }
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    // TODO: Make sure that id is unique
    auto e = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_entitiesToAdd.push_back(e);
    return e;
}

EntityVec& EntityManager::getEntities()
{
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
    return m_entityMap[tag];
}

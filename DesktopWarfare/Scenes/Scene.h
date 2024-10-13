#pragma once

#include "../Entities/EntityManager.h"

class GameEngine;

class Scene {
public:
    Scene(GameEngine& gameEngine);
    virtual ~Scene() = default;

    virtual void update() = 0;
    virtual void sDoAction() = 0;
    virtual void render() = 0;

    void simulate(int times);
    void doAction(std::string action);
    void registerAction();

    int m_frame = 0;
    bool m_isPaused = false;

    EntityManager m_entities;
    std::map<int, std::string> m_actionMap;

private:
    GameEngine& m_gameEngine;
};
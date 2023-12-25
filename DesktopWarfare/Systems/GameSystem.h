#pragma once

class SystemManager;

class GameSystem
{
public:
    GameSystem(SystemManager& systemManager);
    ~GameSystem() = default;

    void init();
    void start();

private:
    SystemManager& m_systemManager;
};
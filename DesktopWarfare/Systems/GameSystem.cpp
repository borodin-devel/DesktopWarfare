#include "GameSystem.h"

#include "SystemManager.h"

GameSystem::GameSystem(SystemManager& systemManager)
    : m_systemManager(systemManager)
{
}

void GameSystem::init()
{
    //m_systemManager.m_settingsSystem.init();
    m_systemManager.m_windowSystem.init();
    m_systemManager.m_inputSystem.init();
}

void GameSystem::start()
{
    init();

    // Main game loop
    while (!m_systemManager.m_windowSystem.shouldClose())
    {
        ClearBackground(BLACK);

        BeginDrawing();
        DrawText("Desktop Warfare", 10, 25, 20, WHITE);
        EndDrawing();
    }
}
#include "InputSystem.h"

#include "SystemManager.h"

InputSystem::InputSystem(SystemManager& systemManager)
    : m_systemManager(systemManager)
{
}

void InputSystem::init()
{
    SetExitKey(KEY_NULL); // Disable the default ESC exit key
}
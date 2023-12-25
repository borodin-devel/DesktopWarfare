#pragma once

#include "raylib-cpp.hpp"

class SystemManager;

class InputSystem
{
public:
    InputSystem(SystemManager& systemManager);
    ~InputSystem() = default;

    void init();

private:
    SystemManager& m_systemManager;
};
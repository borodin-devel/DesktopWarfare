#pragma once

#include "ProgramOptionsSystem.h"
#include "SettingsSystem.h"
#include "WindowSystem.h"
#include "InputSystem.h"
#include "GameSystem.h"

class SystemManager
{
public:
    SystemManager() = default;
    ~SystemManager() = default;

    ProgramOptionsSystem m_programOptionsSystem = ProgramOptionsSystem(*this);
    SettingsSystem m_settingsSystem = SettingsSystem(*this);
    WindowSystem m_windowSystem = WindowSystem(*this);
    InputSystem m_inputSystem = InputSystem(*this);
    GameSystem m_gameSystem = GameSystem(*this);
};
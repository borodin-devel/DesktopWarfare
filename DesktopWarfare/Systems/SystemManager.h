#pragma once

#include "SystemBase.h"
#include "ProgramOptionsSystem.h"
#include "SettingsSystem.h"
#include "WindowSystem.h"

class SystemManager
{
public:
    SystemManager() = default;
    ~SystemManager() = default;

    void setMustReinitialize(bool mustReinitialize) { m_mustReinitialize = mustReinitialize; }
    bool mustReinitialize() const { return m_mustReinitialize; }

    ProgramOptionsSystem m_programOptionsSystem;
    SettingsSystem m_settingsSystem;
    WindowSystem m_windowSystem = WindowSystem(m_settingsSystem);

private:
    bool m_mustReinitialize = true;
};
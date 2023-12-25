#pragma once

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

    ProgramOptionsSystem m_programOptionsSystem = ProgramOptionsSystem(*this);
    SettingsSystem m_settingsSystem = SettingsSystem(*this);
    WindowSystem m_windowSystem = WindowSystem(*this);

private:
    bool m_mustReinitialize = true;
};
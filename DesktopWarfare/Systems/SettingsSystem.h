#pragma once

#include "SystemBase.h"

class SettingsSystem : public SystemBase
{
public:
    SettingsSystem();
    ~SettingsSystem();

    const char* m_windowTitle = "Desktop Warfare";
    const int m_windowMinWidth = 320;
    const int m_windowMinHeight = 240;
    int m_windowWidth = 800;
    int m_windowHeight = 600;
    int m_windowTargetFPS = 60;
    bool m_windowFullscreen = false;
    bool m_windowsVSync = true;
};
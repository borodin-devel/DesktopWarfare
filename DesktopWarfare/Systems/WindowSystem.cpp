#include "WindowSystem.h"

#include "SystemManager.h"

WindowSystem::WindowSystem(SystemManager& systemManager)
    : m_systemManager(systemManager)
{
}

void WindowSystem::init()
{
    SettingsSystem& settingsSystem = m_systemManager.m_settingsSystem;

    // Enable config flags for resizable window and vertical synchro
    m_window = std::make_unique<raylib::Window>(
        settingsSystem.m_windowWidth,
        settingsSystem.m_windowHeight,
        settingsSystem.m_windowTitle,
        FLAG_VSYNC_HINT);
    m_window->SetMinSize(settingsSystem.m_windowMinWidth, settingsSystem.m_windowMinHeight);

    m_window->SetTargetFPS(settingsSystem.m_windowTargetFPS);
}

bool WindowSystem::shouldClose()
{
    return m_window->ShouldClose();
}
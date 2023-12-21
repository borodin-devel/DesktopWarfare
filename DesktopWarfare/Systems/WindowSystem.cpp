#include "WindowSystem.h"

WindowSystem::WindowSystem(SettingsSystem& settingsSystem)
    : m_settingsSystem(settingsSystem)
{
}

void WindowSystem::init()
{
    // Enable config flags for resizable window and vertical synchro
    m_window = std::make_unique<raylib::Window>(
        m_settingsSystem.m_windowWidth,
        m_settingsSystem.m_windowHeight,
        m_settingsSystem.m_windowTitle,
        FLAG_VSYNC_HINT);
    m_window->SetMinSize(m_settingsSystem.m_windowMinWidth, m_settingsSystem.m_windowMinHeight);

    m_window->SetTargetFPS(m_settingsSystem.m_windowTargetFPS);

    // Main game loop
    while(!m_window->ShouldClose()) // Detect window close button or ESC key
    {
        ClearBackground(BLACK);

        BeginDrawing();
        DrawText("Desktop Warfare", 10, 25, 20, WHITE);
        EndDrawing();
    }
}
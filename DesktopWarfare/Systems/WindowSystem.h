#pragma once

#include <memory>

#include "SettingsSystem.h"

#include "raylib-cpp.hpp"

class WindowSystem
{
public:
    WindowSystem(SettingsSystem& settingsSystem);
    ~WindowSystem() = default;

    void init();

private:
    SettingsSystem& m_settingsSystem;
    std::unique_ptr<raylib::Window> m_window;
};
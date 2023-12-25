#pragma once

#include <memory>

#include "raylib-cpp.hpp"

class SystemManager;

class WindowSystem
{
public:
    WindowSystem(SystemManager& systemManager);
    ~WindowSystem() = default;

    void init();

private:
    SystemManager& m_systemManager;
    std::unique_ptr<raylib::Window> m_window;
};
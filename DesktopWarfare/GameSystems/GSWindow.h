#pragma once

#include <memory>

#include "raylib-cpp.hpp"

class GameEngine;

class GSWindow : public raylib::Window {
public:
    GSWindow(GameEngine& gameEngine);
    ~GSWindow() = default;

    void init();

private:
    GameEngine& m_gameEngine;
};
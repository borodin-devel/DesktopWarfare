#pragma once

class GameEngine;

class GSInput
{
public:
    GSInput(GameEngine& gameEngine);
    ~GSInput() = default;

    void init();

private:
    GameEngine& m_gameEngine;
};
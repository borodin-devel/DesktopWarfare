#pragma once

class GameEngine;

class Scene
{
public:
    Scene(GameEngine& gameEngine);
    virtual ~Scene() = default;

private:
    GameEngine& m_gameEngine;
};
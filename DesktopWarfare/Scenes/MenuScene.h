#pragma once

#include "Scene.h"

class GameEngine;

class MenuScene : public Scene {
public:
    MenuScene(GameEngine& gameEngine);
    ~MenuScene() = default;

    void update() override;
    void sDoAction() override;
    void render() override;
};
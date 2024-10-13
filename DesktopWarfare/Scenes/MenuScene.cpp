#include "MenuScene.h"

#include "../GameEngine.h"

MenuScene::MenuScene(GameEngine& gameEngine)
    : Scene(gameEngine)
{
}

void MenuScene::update()
{
    ClearBackground(BLACK);

    BeginDrawing();
    DrawText("Desktop Warfare", 10, 25, 20, WHITE);
    EndDrawing();
}

void MenuScene::sDoAction() {

}


void MenuScene::render() {
    
}
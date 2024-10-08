#include "GameEngine.h"

void GameEngine::init(int argc, char** argv)
{
    m_programOptions.init(argc, argv);
    m_settings.init();
    m_window.init();
    m_input.init();
}

void GameEngine::run()
{
    update();
}

void GameEngine::update()
{
    while (!m_window.ShouldClose()) {
        ClearBackground(BLACK);

        BeginDrawing();
        DrawText("Desktop Warfare", 10, 25, 20, WHITE);
        EndDrawing();
    }
}

void GameEngine::quit()
{
}
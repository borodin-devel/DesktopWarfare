#include "GameEngine.h"
#include "Scenes/MenuScene.h"

void GameEngine::init(int argc, char** argv)
{
    m_programOptions.init(argc, argv);
    m_settings.init();
    m_window.init();
    m_input.init();

    MenuScene* menuScene = new MenuScene(*this);
    m_scenes.insert({"menu", menuScene});

    m_currentScene = m_scenes["menu"];
}

void GameEngine::run()
{
    update();
}

void GameEngine::update()
{
    while (!m_window.ShouldClose()) {
        m_currentScene->update();
    }

    quit();
}

void GameEngine::quit()
{
    delete m_scenes["menu"];
}
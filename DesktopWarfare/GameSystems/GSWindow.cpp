#include "GSWindow.h"

#include "../GameEngine.h"

GSWindow::GSWindow(GameEngine& gameEngine) :
    m_gameEngine(gameEngine)
{
}

void GSWindow::init()
{
    auto& videoSettings = m_gameEngine.getSettings().getVideo();

    int flags = 0;
    if (videoSettings.windowFullscreen)
        flags |= FLAG_FULLSCREEN_MODE;
    if (videoSettings.windowsVSync)
        flags |= FLAG_VSYNC_HINT;
    this->SetConfigFlags(flags);

    this->Init(videoSettings.windowWidth, videoSettings.windowHeight, videoSettings.windowTitle, flags);
    this->SetMinSize(videoSettings.windowMinWidth, videoSettings.windowMinHeight);
    this->SetTargetFPS(videoSettings.windowTargetFPS);
}
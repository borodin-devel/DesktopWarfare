#pragma once

#include <string>

class GameEngine;

class GSSettings
{
public:
    struct Video
    {
        const std::string windowTitle = "Desktop Warfare";
        const int windowMinWidth = 320;
        const int windowMinHeight = 240;
        int windowWidth = 800;
        int windowHeight = 600;
        int windowTargetFPS = 60;
        bool windowFullscreen = false;
        bool windowsVSync = true;
    };

    GSSettings(GameEngine& gameEngine);
    ~GSSettings() = default;

    void init();

    Video& getVideo() { return m_video; }

private:
    GameEngine& m_gameEngine;
    Video m_video;
};
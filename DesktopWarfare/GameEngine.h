#include <map>
#include <string>

#include "GameSystems/GSInput.h"
#include "GameSystems/GSProgramOptions.h"
#include "GameSystems/GSSettings.h"
#include "GameSystems/GSWindow.h"
#include "Scenes/Scene.h"

class GameEngine {
public:
    GameEngine() = default;
    ~GameEngine() = default;

    void init(int argc, char** argv);
    void run();
    void update();
    void quit();

    GSProgramOptions& getProgramOptions() { return m_programOptions; }
    GSSettings& getSettings() { return m_settings; }
    GSWindow& getWindow() { return m_window; }
    GSInput& getInput() { return m_input; }

private:
    Scene* currentScene() { return m_currentScene; }

private:
    bool m_isRunning = false;

    GSProgramOptions m_programOptions = GSProgramOptions(*this);
    GSSettings m_settings = GSSettings(*this);
    GSWindow m_window = GSWindow(*this);
    GSInput m_input = GSInput(*this);

    std::map<std::string, Scene*> m_scenes;
    Scene* m_currentScene = nullptr;
};
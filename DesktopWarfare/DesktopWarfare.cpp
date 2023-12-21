// DesktopWarfare.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <filesystem>
#include "raylib-cpp.hpp"

#include "buildinfo.h"
#include "Utilities/Logger.h"
#include "Systems/SystemManager.h"

const std::filesystem::path executablePath = std::filesystem::current_path();

int main(int argc, char* argv[])
{
    init_logger();

    BOOST_LOG_TRIVIAL(info) << "DesktopWarfare v" << BuildInfo::Version
        << " - Built: " << BuildInfo::Timestamp
        << " - SHA: " << BuildInfo::CommitSHA
        << "\nPath: " << executablePath.string()
        << std::endl;

    try {
        SystemManager systemManager;
        systemManager.m_programOptionsSystem.init(argc, argv);

        while (systemManager.mustReinitialize()) {
            systemManager.setMustReinitialize(false);

            //systemManager.m_settingsSystem.init();

            systemManager.m_windowSystem.init();
        }
    }
    catch (std::exception& e) {
        BOOST_LOG_TRIVIAL(fatal) << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
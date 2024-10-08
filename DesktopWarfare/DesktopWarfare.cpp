// DesktopWarfare.cpp : Defines the entry point for the application.
//

#include <filesystem>
#include <iostream>

#include "GameEngine.h"
#include "Utilities/Logger.h"
#include "buildinfo.h"

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
        GameEngine gameEngine;
        gameEngine.init(argc, argv);
        gameEngine.run();
    } catch (std::exception& e) {
        BOOST_LOG_TRIVIAL(fatal) << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
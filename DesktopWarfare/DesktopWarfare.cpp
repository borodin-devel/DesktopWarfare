// DesktopWarfare.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <boost/program_options.hpp>
#include "raylib-cpp.hpp"

#include "buildinfo.h"

namespace po = boost::program_options;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    std::cout << "DesktopWarfare v" << BuildInfo::Version
        << " - Built: " << BuildInfo::Timestamp
        << " - SHA: " << BuildInfo::CommitSHA
        << std::endl;

    try {
        po::options_description desc("Desktop Warfare command line options:");
        desc.add_options()
            ("help,h", "produce help message");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return EXIT_SUCCESS;
        }

        const int windowWidth = 800;
        const int windowHeight = 600;

        // Enable config flags for resizable window and vertical synchro
        raylib::Window window(windowWidth, windowHeight,
            "Desktop Warfare",
            FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
        window.SetMinSize(320, 240);

        window.SetTargetFPS(60); // Set our game to run at 60 frames-per-second

        // Main game loop
        while (!window.ShouldClose()) // Detect window close button or ESC key
        {
            ClearBackground(BLACK);

            BeginDrawing();
            DrawText("Desktop Warfare", 10, 25, 20, WHITE);
            EndDrawing();
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
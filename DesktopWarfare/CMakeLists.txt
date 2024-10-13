# CMakeList.txt : CMake project for DesktopWarfare, include source and define
# project specific logic here.

include(BuildInfo)

# Add source to this project's executable.
add_executable (DesktopWarfare
    "DesktopWarfare.cpp"
    "Utilities/Logger.h"
    "Utilities/Logger.cpp"
    "GameEngine.h"
    "GameEngine.cpp"
    "GameSystems/GSProgramOptions.h"
    "GameSystems/GSProgramOptions.cpp"
    "GameSystems/GSSettings.cpp"
    "GameSystems/GSSettings.h"
    "GameSystems/GSWindow.h"
    "GameSystems/GSWindow.cpp"
    "GameSystems/GSInput.h"
    "GameSystems/GSInput.cpp"
    "Scenes/MenuScene.h"
    "Scenes/MenuScene.cpp"
    "Scenes/Scene.h"
    "Scenes/Scene.cpp"
    "Components/Component.h"
    "Entities/Entity.h"
    "Entities/EntityManager.h"
    "Entities/EntityManager.cpp"
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET DesktopWarfare PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(DesktopWarfare
    PRIVATE
        raylib
        raylib_cpp
        Boost::program_options
        Boost::log
        Boost::log_setup
        Boost::date_time
)

BuildInfo(DesktopWarfare)

# TODO: Add tests and install targets if needed.

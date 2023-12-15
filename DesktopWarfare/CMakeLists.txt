# CMakeList.txt : CMake project for DesktopWarfare, include source and define
# project specific logic here.

# Add source to this project's executable.
add_executable (DesktopWarfare "DesktopWarfare.cpp" )
target_link_libraries(DesktopWarfare
    PRIVATE
        raylib
        raylib_cpp
        Boost::program_options
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET DesktopWarfare PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

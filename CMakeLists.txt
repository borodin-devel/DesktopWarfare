# CMakeList.txt : Top-level CMake project file, do global configuration and include sub-projects here.

message("CMake version: ${CMAKE_VERSION}")
cmake_minimum_required(VERSION 3.14)

project("DesktopWarfare" VERSION 0.1)

# Global CMake settings
message("\nSetting global CMake variables")
# Generate compile_commands.json for Makefiles and Ninja
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set build type if not provided
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (Debug or Release)" FORCE)
endif()

message("\nInlining CMake scripts")
# Embedded CMake scripts
include(CMakePrintHelpers)
include(FetchContent)
# Project specific CMake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
message("\nCMake module paths: ${CMAKE_MODULE_PATH}")

# Include sub-projects
message("\nFetching dependencies")

# raylib dependency
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG ae50bfa2cc569c0f8d5bc4315d39db64005b1b08 # version 5.0
)
#set(raylib_VERBOSE 1)
set(raylib_BUILD_EXAMPLES OFF CACHE BOOL "Build Raylib examples" FORCE)
set(raylib_BUILD_GAMES OFF CACHE BOOL "Build Raylib games" FORCE)
FetchContent_MakeAvailable(raylib)

# raylib-cpp dependency
FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG 34748ebbecdeaa1868eb2985e8679ba11df84b96 # version 5.0.0
)
FetchContent_MakeAvailable(raylib_cpp)

# Boost dependency
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
set(BOOST_ENABLE_CMAKE ON) # Enable CMake support for Boost
set(Boost_USE_STATIC_LIBS ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_INCLUDE_LIBRARIES program_options log date_time)
FetchContent_MakeAvailable(Boost)

cmake_print_properties(
    TARGETS
        raylib
        raylib_cpp
        Boost::program_options
        Boost::log
        Boost::date_time
    PROPERTIES
        NAME
        TYPE
        VERSION
        SOVERSION
        C_STANDARD
        CXX_STANDARD
        SOURCE_DIR
        BINARY_DIR
        INCLUDE_DIRECTORIES
        INTERFACE_INCLUDE_DIRECTORIES
        PUBLIC_HEADER
        COMPILE_DEFINITIONS
        INTERFACE_COMPILE_DEFINITIONS
        LINK_LIBRARIES
        INTERFACE_LINK_LIBRARIES
)

add_subdirectory("DesktopWarfare")

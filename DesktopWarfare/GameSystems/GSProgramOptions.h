#pragma once

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class GameEngine;

class GSProgramOptions
{
public:
    GSProgramOptions(GameEngine& gameEngine);
    ~GSProgramOptions() = default;

    void init(int argc, char* argv[]);

private:
    GameEngine& m_gameEngine;
    po::options_description m_description = po::options_description("Desktop Warfare command line options:");
    po::variables_map m_vm;
};
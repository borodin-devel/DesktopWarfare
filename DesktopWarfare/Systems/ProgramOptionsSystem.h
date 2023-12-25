#pragma once

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class SystemManager;

class ProgramOptionsSystem
{
public:
    ProgramOptionsSystem(SystemManager& systemManager);
    ~ProgramOptionsSystem() = default;

    void init(int argc, char* argv[]);

private:
    SystemManager& m_systemManager;
    po::options_description m_description = po::options_description("Desktop Warfare command line options:");
    po::variables_map m_vm;
};
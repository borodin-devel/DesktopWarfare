#pragma once

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class ProgramOptionsSystem
{
public:
    ProgramOptionsSystem() = default;
    virtual ~ProgramOptionsSystem();

    void init(int argc, char* argv[]);

private:
    po::options_description m_description = po::options_description("Desktop Warfare command line options:");
    po::variables_map m_vm;
};
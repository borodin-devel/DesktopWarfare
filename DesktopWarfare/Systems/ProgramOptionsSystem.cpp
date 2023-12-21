#include "ProgramOptionsSystem.h"

#include <iostream>

ProgramOptionsSystem::~ProgramOptionsSystem()
{
}

void ProgramOptionsSystem::init(int argc, char* argv[])
{
    m_description.add_options()
        ("help,h", "produce help message");

    po::store(po::parse_command_line(argc, argv, m_description), m_vm);
    po::notify(m_vm);

    if (m_vm.count("help")) {
        std::cout << m_description << std::endl;
        std::exit(EXIT_SUCCESS);
    }
}
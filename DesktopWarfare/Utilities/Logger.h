#pragma once

#include <iostream>
#include <fstream>
#include <boost/log/trivial.hpp>

class Logger {
public:
    Logger() = default;
    ~Logger() = default;

    void init();

private:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

private:
    std::streambuf* originalCoutStreamBuffer = nullptr;
};
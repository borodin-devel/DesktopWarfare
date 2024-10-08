#include "Logger.h"

#include <boost/log/attributes.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <chrono>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

// Function to get the application's start time
std::chrono::system_clock::time_point getStartTime()
{
    static auto start_time = std::chrono::system_clock::now();
    return start_time;
}

// Function to calculate and return the uptime
std::chrono::milliseconds getUptime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - getStartTime());
}

// Function to convert milliseconds to hours, minutes, seconds, and milliseconds
std::string formatMilliseconds(std::chrono::milliseconds ms)
{
    using namespace std::chrono;

    auto hours = duration_cast<std::chrono::hours>(ms);
    ms -= duration_cast<milliseconds>(hours);

    auto minutes = duration_cast<std::chrono::minutes>(ms);
    ms -= duration_cast<milliseconds>(minutes);

    auto seconds = duration_cast<std::chrono::seconds>(ms);
    ms -= duration_cast<milliseconds>(seconds);

    return std::to_string(hours.count()) + ":"
        + std::to_string(minutes.count()) + ":"
        + std::to_string(seconds.count()) + ":"
        + std::to_string(ms.count());
}

void init_logger()
{
    logging::add_common_attributes();

    // Set up the console sink
    logging::add_console_log(std::cout);

    logging::add_file_log(
        keywords::file_name = "dwlogfile_%N.log",
        keywords::format = (expr::stream
            << "[" << formatMilliseconds(getUptime()) << "]["
            << expr::attr<logging::trivial::severity_level>("Severity") << "] "
            << expr::message));

    // Set the logging severity level
    logging::core::get()->set_filter(
        logging::trivial::severity >= logging::trivial::info);
}
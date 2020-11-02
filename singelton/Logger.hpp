//
//  Logger.hpp
//  DesignPatterns
//
//  Created by Michael Ferraro on 11/1/20.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

namespace design {

// Definition of a singleton logger class.
class Logger final
{
public:
    enum class LogLevel {
        Error,
        Info,
        Debug
    };

    // Returns a reference to the singleton Logger object.
    // The local static instance is initialized in a thread-safe fashion
    static Logger& instance();

    // Prevent copy/move construction.
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;

    // Prevent copy/move assignment operations.
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    // Sets the log level.
    void setLogLevel(LogLevel level);

    // Logs a single message at the given log level.
    void log(std::string_view message, LogLevel logLevel);

    // Logs a vector of messages at the given log level.
    void log(const std::vector<std::string>& messages,
        LogLevel logLevel);
private:
    // Private constructor and destructor.
    Logger();
    ~Logger();

    // Converts a log level to a human readable string.
    std::string_view getLogLevelString(LogLevel level) const;

    static const char* const theLogFileName;
    std::ofstream theOutPutStream;
    LogLevel theLogLevel = LogLevel::Error;
};

} // namespace design

#endif /* Logger_hpp */

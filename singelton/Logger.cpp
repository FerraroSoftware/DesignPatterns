//
//  Logger.cpp
//  DesignPatterns
//
//  Created by Michael Ferraro on 11/1/20.
//

#include "Logger.hpp"

#include <stdexcept>

using namespace std;

namespace design {

const char* const Logger::theLogFileName = "/tmp/log.out";

//##############################################################################
// Logger::Instance
//##############################################################################
Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

//##############################################################################
// Logger::Logger
//##############################################################################
Logger::Logger()
{
    theOutPutStream.open(theLogFileName, ios_base::app);
    if (!theOutPutStream.good())
    {
        throw runtime_error("Unable to initialize the Logger!");
    }
}

//##############################################################################
// Logger::~Logger
//##############################################################################
Logger::~Logger()
{
    theOutPutStream << "Logger shutting down." << endl;
    theOutPutStream.close();
}

//##############################################################################
// Logger::setLogLevel
//##############################################################################
void Logger::setLogLevel(LogLevel level)
{
    theLogLevel = level;
}

//##############################################################################
// Logger::getLogLevelString
//##############################################################################
string_view Logger::getLogLevelString(LogLevel level) const
{
    switch (level)
    {
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Debug:
            return "DEBUG";
    }
    throw runtime_error("Invalid log level.");
}

//##############################################################################
// Logger::log
//##############################################################################
void Logger::log(string_view message, LogLevel logLevel)
{
    if (theLogLevel < logLevel) return;
    
    theOutPutStream << getLogLevelString(logLevel).data()
        << ": " << message << endl;
}

//##############################################################################
// Logger::log
//##############################################################################
void Logger::log(const vector<string>& messages, LogLevel logLevel)
{
    if (theLogLevel < logLevel) return;

    for (const auto& message : messages) {
        log(message, logLevel);
    }
}

} // namespace design

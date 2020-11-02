//
//  main.cpp
//  DesignPatterns
//
//  Created by Michael Ferraro on 11/1/20.
//

#include "singelton/Logger.hpp"

using namespace design;
using namespace std;

int main(int argc, const char * argv[]) {

    // TODO:
    // 1. Adding timing to log messages
    // 2. Give user option to pass in path to save file, defaut to tmp of user
    // 3. Clean up file from tmp at end if we want fresh start everytime.
    //    Real application would want to keep in non-volatile memory
    
    // Set log level to Debug.
    Logger::instance().setLogLevel(Logger::LogLevel::Debug);

    // Log some messages.
    Logger::instance().log("Hopefully we wont have to use these debug logs :)", Logger::LogLevel::Debug);
    vector<string> items = {"Epic failure", "Did not compute :("};
    Logger::instance().log(items, Logger::LogLevel::Error);

    // Set log level to Error.
    Logger::instance().setLogLevel(Logger::LogLevel::Error);
    // Now that the log level is set to Error, logging a Debug
    // message will be ignored.
    Logger::instance().log("A debug message", Logger::LogLevel::Debug);
    
    return 0;
}

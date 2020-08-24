#include <iostream>

class LogManager {
    private:
        static LogManager* instance;
        LogManager() {}

    public:
        static LogManager* getInstance();
        void error();
        void warning();
        void info();
};

LogManager* LogManager::instance = 0;

LogManager* LogManager::getInstance() {
    if (instance == 0) {
        instance = new LogManager();
    }

    return instance;
}

void LogManager::error() {
    std::cout << "Error" << std::endl;
}

void LogManager::warning() {
    std::cout << "Warning" << std::endl;
}

void LogManager::info() {
    std::cout << "Info" << std::endl;
}

int main() {
    LogManager* singlton1 = LogManager::getInstance();
    std::cout << singlton1 << std::endl; 
    LogManager* singlton2 = LogManager::getInstance();
    std::cout << singlton2 << std::endl;
    
    singlton1->error();
    singlton1->warning();
    singlton1->info();
}
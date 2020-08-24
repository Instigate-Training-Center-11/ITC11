#include <iostream>

class LogManager {
    private:
        static LogManager *obj;
        LogManager() {}
    public:
        void error() {
            std::cout << "Error" << "\n";
        }
        void warning() {
            std::cout << "Warning" << "\n";
        }
        void info() {
            std::cout << "Info" << "\n";
        }
    static LogManager* getInstance() {
        if(obj == NULL) {
            obj = new LogManager();
        }
        return obj;
    }
};

LogManager* LogManager::obj = NULL;

int main() {
    std::cout << "Singleton design pattern\n" << "\n";

    LogManager* obj = LogManager::getInstance();
    obj->error();
    obj->warning();
    obj->info();

    return 0;
}
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

class MyException : public std::exception {
    private:
        std::string message;
    public:
        MyException (const char*);
        const char *what();
};

#endif
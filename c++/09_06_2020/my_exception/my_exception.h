#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <iostream>

    /* This is a list.h file that represents List the type that the user created. */
    class MyException : std::exception {
        private:
            std::string msg;
        public:
            MyException (const char *msg);
            const char *what();
    };

#endif
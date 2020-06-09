#include "node.h"
#include <iostream>

#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

    /* This is a list.h file that represents List the type that the user created. */
    class MyException : std::exception {
        private:
            int index;
        public:
            myException(char *msg) : std::exception(){}
            int noneIndex();
    };

#endif
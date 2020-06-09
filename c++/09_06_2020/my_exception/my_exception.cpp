#include "my_exception.h"

/* Constructor MyException*/
MyException::MyException(const char *msg) {
    this->msg = msg;
}

/* Given my error */
const char *MyException::what() {
    return msg.c_str();
}
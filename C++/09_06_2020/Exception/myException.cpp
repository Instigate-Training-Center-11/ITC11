#include <iostream>
#include "myException.h"

MyException::MyException(const char *message)  {
    this->message = message;
}

const char *MyException::what() {
    return message.c_str();
}
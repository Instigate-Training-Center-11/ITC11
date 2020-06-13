#include <iostream>
#include <string>
#ifndef _MY_EXCEPTION_HPP
#define _MY_EXCEPTION_HPP

class my_exception : protected std::exception {
    private:
        std::string my_error;
        int error_code;
    public:
    my_exception(std::string my_error, int code):my_error(my_error), error_code(code) {
        std::cout << "Error code: " << error_code << std::endl;
    }

    const char* what() const noexcept {
        return my_error.c_str();
    }
};

#endif
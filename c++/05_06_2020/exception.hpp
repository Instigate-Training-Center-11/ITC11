#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <string>


class customException {
private:
	std::string m_error;
public:
	customException(std::string error):m_error(error){
	}
	const char* getError() {
        return m_error.c_str();
    }
};
#endif
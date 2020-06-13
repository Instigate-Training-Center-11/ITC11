#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <string>


class customException : public std::exception {
private:
	std::string m_error;
public:
	customException(std::string error):m_error(error){
	}
	virtual const char * what () const throw () {
        m_error.c_str();
		return m_error.c_str();
    }
};

#endif
#include <iostream>
#include <string>

class my_exception : protected std::exception {
private:
    std::string my_error;
public:
    my_exception(std::string my_error):my_error(my_error) { }
    const char* what() const noexcept {
        return my_error.c_str();
    }
};

int divide(int, int);

int main() {
    try {
        int value = divide(4, 0);
    } catch (my_exception& ex) {
        std::cerr << ex.what();
    } catch (std::exception& ex) {
        std::cerr << "Standart exception" << ex.what();
    }
    return 0;
}

int divide(int first, int second) {
    if (0 == second) {
        throw my_exception("divide in zero!\n");
    } else {
        return (first/second);
    }
}
#include "ugly.h"

int main() {
    int f2 = 1;
    int f3 = 1;
    int f5 = 1;
    int count = 0;
    int n;
    while (true) {
        std::cout << "search ugly number by position -> ";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
        } else {
            std::cin.ignore(32767, '\n');
            break;
        }
    }

    std::cout << "Ugly number -> " << uglyNumberDynamic(n,count) << std::endl;

    return 0;
}

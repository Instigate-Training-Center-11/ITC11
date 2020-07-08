#include "ugly.h"

int main() {
    std::vector<int> data(2,0);
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

    std::cout << "Ugly number -> " << uglyNumberDynamic(n,data) << std::endl;
    std::cout << "\n---------" << data[24] << "\n";
    data.clear();
    return 0;
}

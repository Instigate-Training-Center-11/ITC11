#include <iostream>

int main() {
    int n = 0;

    while (n < 2) {
        std::cout << "Enter n: ";
        std::cin >> n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                std::cout << '*';
                std::cout << ' ';
            }
            else if (i == j) {
                int k = i;
                for (k = 0; k < i; ++k) {
                    std::cout << ' ';
                }
                std::cout << '*';
                if (i == n - 1) {
                    break;
                }
                for (int t = 3; t < (2 * n) - (2 * k); ++t) {
                    std::cout << ' ';
                }
                std::cout << '*';
            }
        }

        std::cout << "\n";
    }

    return 0;
}

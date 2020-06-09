#include <iostream>

int div(int num1, int num2) {
    try {
        if (num2 == 0) {
            throw 1;
        }
        std::cout << num1 / num2 << std::endl;
    } catch (int i) {
        std::cout << " Error N " << i << " cannot divide by 0!" << std::endl;
    }
    return num1/num2;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    int arr[3] = {-4, 5, 6};
    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;
    std::cout << "Div = " << div(num1, num2) << std::endl;
    for (int i = 0; i < 3; i++) {
        int e = arr[i];
        int ex = arr[14];
        try {
            if (e < 0) {
                throw e;
            }
        } catch (int e) {
            std::cout << "Wrong element: " << e << std::endl;
        }
        throw ex;
    }
    return 0;
}


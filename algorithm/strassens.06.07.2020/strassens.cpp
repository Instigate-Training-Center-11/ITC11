#include <iostream>

int main() {

    int matrixOne[2][2] {};
    int matrixTwo[2][2] {};
    int multiplicationResult[2][2] {};
    int i = 0, j = 0;
    int m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m6 = 0, m7 = 0;

    std::cout << "Enter the 4 elements of matrixOne:\n";
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            while (true) {
                std::cout << "matrixOne[" << i << "]" << "[" << j << "] = ";
                std::cin >> matrixOne[i][j];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
                }  else {
                    std::cin.ignore(32767,'\n');
                    break;
                }
            }
        }
    }

    std::cout << "\nEnter the 4 elements of matrixTwo:\n";
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
             while (true) {
                std::cout << "matrixTwo[" << i << "]" << "[" << j << "] = ";
                std::cin >> matrixTwo[i][j];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
                } else {
                    std::cin.ignore(32767,'\n');
                    break;
                }
            }
        }
    }

    std::cout << "\nThe matrixOne is\n";
    for(i = 0; i < 2; ++i) {
        std::cout << "\n";
        for(j = 0; j < 2; ++j) {
            std::cout << matrixOne[i][j] << " ";
        }
    }

    std::cout << "\n\nThe matrixTwo is\n";
    for(i = 0; i < 2; ++i) {
        std::cout << "\n";
        for(j = 0; j < 2; ++j) {
            std::cout << matrixTwo[i][j] << " ";
        }
    }

    m1 = (matrixOne[0][0] + matrixOne[1][1]) * (matrixTwo[0][0] + matrixTwo[1][1]);
    m2 = (matrixOne[1][0] + matrixOne[1][1]) * matrixTwo[0][0];
    m3 = matrixOne[0][0] * (matrixTwo[0][1] - matrixTwo[1][1]);
    m4 = matrixOne[1][1] * (matrixTwo[1][0] - matrixTwo[0][0]);
    m5 = (matrixOne[0][0] + matrixOne[0][1]) * matrixTwo[1][1];
    m6 = (matrixOne[1][0] - matrixOne[0][0]) * (matrixTwo[0][0] + matrixTwo[0][1]);
    m7 = (matrixOne[0][1] - matrixOne[1][1]) * (matrixTwo[1][0] + matrixTwo[1][1]);

    multiplicationResult[0][0] = m1 + m4 - m5 + m7;
    multiplicationResult[0][1] = m3 + m5;
    multiplicationResult[1][0] = m2 + m4;
    multiplicationResult[1][1] = m1 - m2 + m3 + m6;

    std::cout <<"\n\nAfter multiplication using Strassen's algorithm\n";
    for(i = 0; i < 2 ; ++i) {
        std::cout << "\n";
        for(j = 0; j < 2; ++j) {
            std::cout << multiplicationResult[i][j] << " ";
        }
    }
    std::cout<< "\n";
    return 0;
}
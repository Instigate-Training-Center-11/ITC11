#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

/* This function selects mathematics activities */
int mathAct(int num1, char simbol, int num2) {
    if ('+' == simbol) {
        return num1 + num2;
    } else if ('-' == simbol) {
        return num1 - num2;
    } else if ('*' == simbol) {
        return num1 * num2;
    } else if ('/' == simbol) {
        return num1 / num2;
    } else {
        return num1 % num2;
    }
    return 0;
}

int main() {
    std::ifstream out1("number1.txt");
    std::ifstream out2("math.txt");
    std::ifstream out3("number2.txt");
    std::ofstream in("number4.txt");
    std::string line1 = " ";
    std::string line2 = " ";
    std::string line3 = " ";
    int number1 = 0;
    int number2 = 0;

    if (!in.is_open() || !out1.is_open() || !out2.is_open() || !out3.is_open()) {
        std::cerr << "Can't open the file!" << std::endl;
        return -1;
    }

    /* Goes through 3 files, perform activities and write in the 4th file. */
    if (out1.is_open() && out2.is_open() && out3.is_open()) {
        while (!out1.eof()) {
            std::getline(out1, line1);
            number1 = std::stoi(line1);
            while (!out2.eof()) {
                std::getline(out2, line2);
                while (!out3.eof()) {
                    std::getline(out3, line3);
                    number2 = std::stoi(line3);
                    in << number1 << " " << line2[0] << " " << number2 << " = " <<
                    mathAct(number1, line2[0], number2) << "\n";
                }

                if(out3.is_open()) {
                    out3.clear();
                    out3.seekg(0, std::ios::beg);
                }
            }

            if(out2.is_open()) {
                out2.clear();
                out2.seekg(0, std::ios::beg);
            }
        }
    }
    out1.close();
    out2.close();
    out3.close();
    in.close();

    return 0;
}
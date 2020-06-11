#include <fstream>
#include <iostream>

/* Function for performing math operatiions. */
int arithmetic(int num1, char symbol, int num2) {
    switch (symbol) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        case '/':
            try {
                if (num2 == 0) {
                    throw 1;
                }
            } catch (int i) {
                std::cout << " Error N " << i << " cannot divide by 0!" << std::endl;
            }

            return num1 / num2;
            break;
        case'%':
            try {
                if (num2 == 0) {
                    throw 1;
                }
            } catch (int i) {
                std::cout << " Error N " << i << " cannot divide by 0!" << std::endl;
            }
            return num1 % num2;
            break;
    }

    return 0;
}

int main() {
    std::ifstream file1("num1.txt");
    std::ifstream file2("oper.txt");
    std::ifstream file3("num2.txt");
    std::ofstream file4("result.txt");
    std::string line1;
    std::string line2;
    std::string line3;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    if (file1.is_open() && file2.is_open() && file3.is_open()) {
        while (getline(file1, line1)) {
            num1 = std::stoi(line1);
            while (getline(file2, line2)) {
                while (getline(file3, line3)) {
                    num3 = std::stoi(line3);
                    file4 << num1 << " " << line2[0] << " " << num3 << " = " <<
                        arithmetic(num1, line2[0], num3) << "\n";
                }
                if(file3.is_open()) {
                    file3.clear();
                    file3.seekg(0, std::ios::beg);
                }
            }
            if(file2.is_open()) {
                file2.clear();
                file2.seekg(0, std::ios::beg);
            }
        }
    }
    file1.close();
    file2.close();
    file3.close();

    return 0;
}


#include <iostream>
#include <fstream>
#include <stdlib.h>


bool files(std::ifstream& file1, std::ifstream& file2, std::ifstream& file3);
void arithmetic(std::ifstream& file1, std::ifstream& file2, std::ifstream& file3, std::ofstream& output);

int main () {

    std::ifstream file1("./number1.txt");
    std::ifstream file2("./number2.txt");
    std::ifstream file3("./operand.txt");
    std::ofstream output("./output.txt");

    if (files(file1, file2, file3)) {
        arithmetic(file1, file2, file3,output);
    }

    file1.close();
    file2.close();
    file3.close();
    output.close();
    return 0;
}

bool files(std::ifstream& file1, std::ifstream& file2, std::ifstream& file3) {
    try {
        if(!file1) {
            throw "cannot open file1 \n";
	    }
        if(!file2) {
            throw "cannot open file2 \n";
        }
        if(!file3) {
            throw "cannot open file3 \n";
        }
    } catch (const char* exception) {
        std::cerr << "Error " << exception;
        return false;
    }
    return true;
}

void arithmetic (std::ifstream& file1, std::ifstream& file2, std::ifstream& file3,std::ofstream& output) {
    std::string str1;
    std::string str2;
    std::string str3;
    std::string c;
    double num1 = 0;
    double num2 = 0;
    while (std::getline(file1,str1) && std::getline(file2,str2) && std::getline(file3,c)) {

        std::cout << "str1 " << str1 << "\tstr2 " << str2 << "char\t" << c <<std::endl;
        num1 = std::stoi(str1);
        num2 = std::stoi(str2);
        switch (c[0]) {
            case '+':
                output << str1 << " + " << str2 << " = " << num1 + num2 << std::endl;
                break;
            case '-':
                output << str1 << " - " << str2 << " = " << num1 - num2 << std::endl;
                break;
            case '*':
                output << str1 << " * " << str2 << " = " << num1 * num2 << std::endl;
                break;
            case '/':
                try {
                    if (0 == num2 && num1 != 0) {
                        throw "you cannot divide the number by zero";
                    } else {
                        output << str1 << " / " << str2 << " = " << num1 / num2 << std::endl;
                    }
                } catch (const char* exception) {
                    output << str1 << " / " << str2 << " = " << exception << std::endl;
                }
                break;
            default:
                break;
        }

    }

}

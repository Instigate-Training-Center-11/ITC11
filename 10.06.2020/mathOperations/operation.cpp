#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int operations(int number1, int number2, char mathOp);
std::string to_string(int value);

int main() {

    int temp1 = 0;
    int temp2 = 0;
    char temp3 = ' ';
    std::string temp = "";

    /* open 1.txt file where first block of numbers is located */
    std::ifstream inFile1;
    inFile1.open("1.txt");

    /* open 2.txt file where second block of numbers is located */
    std::ifstream inFile2;
    inFile2.open("2.txt");

    /* open 3.txt file where math operators are located */
    std::ifstream inFile3;
    inFile3.open("3.txt");

    /* open 4.txt file where result must be located */
    std::ofstream inFile4;
    inFile4.open("4.txt");

    /* check whether 1.txt, 2.txt, 3.txt files exist,
    if one of them does not exist send a msg obut it,
    else go on to do math operations */
    if (!inFile1.is_open() || !inFile2.is_open() || !inFile3.is_open()) {
        std::cerr << "File does not exist!" << std::endl;
    } else {
        while (!inFile1.eof()) {
            inFile1 >> temp1;
            std::string temp = to_string(temp1);
            temp += " ";

            inFile3 >> temp3;
            temp += temp3;
            temp += " ";

            inFile2 >> temp2;
            temp += to_string(temp2);
            temp += " = ";
            temp += to_string(operations(temp1, temp2, temp3));
            temp += "\n";

            inFile4 << temp;
            temp = " ";
        }
    }

    /* close opened files */
    inFile1.close();
    inFile2.close();
    inFile3.close();
    inFile4.close();

    return 0;
}

/* function to turn int into string */
std::string to_string(int value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

/* function to performe some basic mathematics operations */
int operations(int number1, int number2, char mathOp) {
    switch (mathOp) {
        case '+':
            return number1 + number2;
            break;

        case '-':
            return number1 - number2;
            break;

        case '*':
            return number1 * number2;
            break;

        case '/':
            return number1 / number2;
               break;

        case '%':
            return number1 % number2;
            break;

        default:
            std::cout << "Error.. Invalid operation.";
            return 0;
            break;
    }
}
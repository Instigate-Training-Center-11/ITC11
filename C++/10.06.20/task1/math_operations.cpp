
#include <iostream>
#include <fstream>

int math_ops(int, int, char);

int main() {
    char tmp_oper = ' ';
    int tmp_first = 0;
    int tmp_second = 0;
    std::string result_string = "";

    std::fstream first;
    std::fstream second;
    std::fstream oper;
    std::fstream result;

    first.open("first");
    second.open("second");
    oper.open("oper");
    result.open("result");

    if (first.fail() || second.fail() || oper.fail() || result.fail()) {
        std::cout<<"Error open file!\n";
	    exit(1);
    }

    while (!first.eof()) {
        first >> tmp_first;
        result_string = std::to_string(tmp_first);
        result_string += " ";
        oper >> tmp_oper;
        result_string += tmp_oper;
        result_string += " ";
        second >> tmp_second;
        result_string += std::to_string(tmp_second);
        result_string += " = ";
        result_string += std::to_string(math_ops(tmp_first, tmp_second, tmp_oper));
        result_string += "\n";
        result << result_string;
        result_string = "";
    }

    first.close();
    second.close();
    oper.close();
    result.close();

    return 0;
}

/* Return result of operation */
int math_ops(int first, int second, char simvol) {
    switch (simvol) {
        case '+':
            return first + second;
        break;
        case '-':
            return first - second;
        break;
        case '*':
            return first * second;
        break;
        case '/':
            return first / second;
        break;
        default:
            std::cout << "Error! Invalid operation" << std::endl;
            return 0;
        break;
    }
}
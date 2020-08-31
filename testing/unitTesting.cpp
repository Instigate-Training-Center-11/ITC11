#include <iostream>
#include <fstream>

float calculator(float value1, char operand, float value2);
void unitTest(std::ofstream& output);

int main () {

    std::ofstream result("./result.txt");

    unitTest(result);


    result.close();
    return 0;
}


float calculator(float value1, char operand, float value2) {

    switch (operand) {

    case '+':
        return value1 + value2;
        break;
    case '-':
        return value1 - value2;
        break;

    case '*':
        return value1 * value2;
        break;
    case '/':
        if(operand == '/' && value2 == 0) {
            return -999999;
        }
        return value1 / value2;
        break;

    default:
        std::cout<<"undefined operand" << std::endl;
        break;
    }
}

void unitTest(std::ofstream& output) {

    output << "5 + 10 = " << calculator(5,'+',10) << std::endl;
    output << "-5 + (-10) = " << calculator(-5,'+',-10) << std::endl;
    output << "15 + (-5) = " << calculator(15,'+',-5) << std::endl;

    if (calculator(5,'+',10) == 15 && calculator(-5,'+',-10) == -15 && calculator(15,'+',-5) == 10) {
        output << "test operand + passed"  << std::endl;
    } else {
        output << "test operand + failed"  << std::endl;
    }

    output<<"================="<<std::endl;
    output << "5 - 10 = " << calculator(5,'-',10) << std::endl;
    output << "-5 - (-10) = " << calculator(-5,'-',-10) << std::endl;
    output << "-5 - 10 = " << calculator(-5,'-',10) << std::endl;

    if (calculator(5,'-',10) == -5 && calculator(-5,'-',-10) == 5 && calculator(-5,'-',10) == -15) {
        output << "test operand - passed"  << std::endl;
    } else {
        output << "test operand - failed"  << std::endl;
    }

    output<<"================="<<std::endl;
    output << "5 * 10 = " << calculator(5,'*',10) << std::endl;
    output << "-5 * (-10) = " << calculator(-5,'*',-10) << std::endl;
    output << "-5 * 10 = " << calculator(-5,'*',10) << std::endl;

    if (calculator(5,'*',10) == 50 && calculator(-5,'*',-10) == 50 && calculator(-5,'*',10) == -50) {
        output << "test operand * passed"  << std::endl;
    } else {
        output << "test operand * failed "  << std::endl;
    }

    output << "=================" << std::endl;
    output << "72 / 10 = " << calculator(72,'/',10) << std::endl;
    output << "-5 / (-10) = " << calculator(-5,'/',-10) << std::endl;
    output << "-5 / 10 = " << calculator(-5,'/',10) << std::endl;
    output << "-5 / 0 = " << calculator(-5,'/',0) << std::endl;

    if (calculator(-5,'/',-10) == float(0.5) && calculator(-5,'/',10) == float(-0.5) &&
        calculator(72,'/',0) == -999999 && calculator(72,'/',10) == float(7.2)) {
        output << "test operand / passed"  << std::endl;
    } else {
        output << "test operand / failed"  << std::endl;
    }

}
#include <fstream>
#include <iostream>

/* Function for performing math operatiions. */
int result(int op1, char ch, int op2) {
    switch (ch) {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;   
    default:
        break;
    }
    return 0;
}
 
int main() {
    std::ifstream f1("1.txt");
    std::ifstream f2("2.txt");
    std::ifstream f3("3.txt");
    std::ofstream f4("4.txt");
    std::string line1;
    std::string line2;
    std::string line3;
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;

    if (f1.is_open() && f2.is_open() && f3.is_open()) {
        while (getline(f1, line1)) {
            val1 = std::stoi(line1);
            while (getline(f2, line2)) {
                while (getline(f3, line3)) {
                    val3 = std::stoi(line3);
                    f4 << val1 << " " << line2[0] << " " << val3 << " = " <<
                    result(val1, line2[0], val3) << "\n";
                }
                if(f3.is_open()) {
                    f3.clear();             
                    f3.seekg(0, std::ios::beg);
                }
            }
            if(f2.is_open()) {
                f2.clear();             
                f2.seekg(0, std::ios::beg);
            }
        }
    } 
    f1.close();
    f2.close();
    f3.close();

    return 0;
}
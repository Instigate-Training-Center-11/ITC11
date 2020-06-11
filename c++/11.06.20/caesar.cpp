#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void encrypt(std::string str, int shift) {
    std::ifstream in("String.txt");
    if (in.is_open()) {
        while (std::getline(in,str)) {
            for (int i = 0; i < str.length(); i++) {
                str[i] = (str[i] + shift);
            }
            std::cout << "Code string: " << str << '\n';
        }

    }
    in.close();
}

void decrypt(std::string str, int shift) {
    std::ifstream in("String.txt");
    if (in.is_open()) {
        while (std::getline(in,str)) {
            for (int i = 0; i < str.length(); i++) {
                str[i] = (str[i] - shift);
            }
            std::cout << "Code string: " << str << '\n';
        }
    }
    in.close();
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    std::string str;
    int shift = std::atoi(argv[2]);
    if (n == 0) {
        std::cout << "After Encrypting!" << std::endl;
        encrypt(str, shift);
    } else {
        std::cout << "After Decrypting!" << std::endl;
        encrypt(str, shift);
    } else {
        std::cout << "After Decrypting!" << std::endl;
        decrypt(str,shift);}

    return 0;
}


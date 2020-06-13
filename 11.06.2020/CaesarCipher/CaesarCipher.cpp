#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>

template <typename T>
int toInt(T value) {
    std::stringstream str;
    str << value;
    int integer = 0;
    str >> integer;
    return integer;
}

int checkKey (int key) {
    int n = 0;
    if (key >= 0) {
        if(key < 26) {
            return key;
        } else {
            n = (key / 25);
            key = key - 25 * n - 1;
            return key;
        }
    } else {
        std::cout << "Key is incorrect." << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (4 > argc) {
        std::cout << "Some arguments are missing..." << std::endl;        
    } else {
        char tempChar ='\0';
        std::string tempString = "";

        int key = toInt(argv[2]);
        char* operation = argv[3];
        std::string filename = argv[1];
        
        key = checkKey(key);

        if (filename != "file.txt") {

            std::cout << "Filename is incorrect.." << std::endl;
            exit(1);
        }
        std::ifstream file;
        file.open("file.txt");

        std::ofstream newfile;
        newfile.open("code.txt");

        if (!file.is_open()) {
            std::cerr << "File does not exist." << std::endl;
        } else {
            while (!file.eof()) {
                tempString = "";
                file >> tempChar;

                tempChar = tolower(tempChar);

                if (strcmp("encrypt", operation) == 0) {
                    if (tempChar >= 'a' && tempChar <= 'm') {
                        tempChar += key;
                    } else if (tempChar >= 'n' && tempChar <= 'z') {
                        tempChar -= (key-2);
                    }

                    std::string tempString = std::string(1, tempChar);
                    newfile << tempString;

                } else if (strcmp("decrypt", operation) == 0) {
                    if (tempChar >= 'a' && tempChar <= 'm') {
                        if (key <= (tempChar - 'a')) {
                            tempChar -= key;
                        } else {
                            tempChar += (26 - key);
                        }
                    } else if (tempChar >= 'n' && tempChar <= 'z') {
                        tempChar -= key;
                    }

                    std::string tempString = std::string(1, tempChar);
                    newfile << tempString;

                } else {
                    std::cout << "Operation is incorrect." << std::endl;
                    exit(1);
                }
            }
        }
    }
    return 0;
}
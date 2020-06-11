#include <iostream>
#include <fstream>
#include <cstring>

/*
first argument - file_name
second argument - key
third argument - encrypt or decrypt
*/
std::string coding(std::string, int);
std::string decoding(std::string, int);
void cesar(std::string, int, bool);

int main(int argc, const char** argv) {
    bool  bo;
    if (strcmp(argv[3], "encrypt")) {
        bo = false;
    } else if (strcmp(argv[3], "decrypt")) {
        bo = true;
    } else {
        return -1;
    }

    int caesarKey = std::stoi(argv[2]);
    cesar(argv[1], caesarKey, bo);

    return 0;
}

std::string coding(std::string str, int key) {
    std::string codTxt = "";
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            codTxt += char(int(str[i] + key - 65) % 26 + 65);
        } else if (islower(str[i])) {
            codTxt += char(int(str[i] + key - 97) % 26 + 97);
        } else {
            codTxt += str[i];
        }
    }
    return codTxt;
}

std::string decoding(std::string str, int key) {
    std::string deCodTxt = "";
    (26 > key) ? key : (key %= 26);
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            if((65 > ((int)str[i] - key))) {
                deCodTxt += char(int(str[i] + (26 - key)));
            } else {
                deCodTxt += char(int(str[i] - key - 65) % 26 + 65);
            }
        } else if (islower(str[i])) {
            if((97 > ((int)str[i] - key))) {
                deCodTxt += char(int(str[i] + (26 - key)));
            } else {
                deCodTxt += char(int(str[i] - key - 97) % 26 + 97);
            }
        } else {
            deCodTxt += str[i];
        }
    }
    return deCodTxt;
}

void cesar(std::string fileName, int key, bool bo) {
    std::ifstream fin(fileName);
    std::string txt = "";
    std::string line = "";

    if (!fin.is_open()) {
        std::cerr << "Can't open the file!" << std::endl;
    }

    while (!fin.eof()) {
        std::getline(fin,line);
        txt = txt + "\n" + line;
    }

    if(bo) {
        std::string newTxt = coding(txt, key);
        std::ofstream fout("2.txt");
        if (!fout.is_open()) {
            std::cerr << "Can't open first file!" << std::endl;
        }
        fout << newTxt;
        fout.close();
    } else {
        std::string newTxt = decoding(txt, key);
        std::ofstream fout("2.txt");
        if (!fout.is_open()) {
            std::cerr << "Can't open first file!" << std::endl;
        }
        fout << newTxt;
        fout.close();
    }
    fin.close();
}

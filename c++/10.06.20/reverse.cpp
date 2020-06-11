#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("newFile.txt");
    std::ifstream in("fileName.txt", std::ios::in | std::ios::ate);
    long size = in.tellg();
    char str;

    while(in) {
        in.seekg(size--);
        in.get(str);
        if(size == -1) {
            break;
        }
        out << str;
    }
    return 0;
}


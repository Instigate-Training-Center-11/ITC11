#include <iostream>
#include <fstream>

int main() {
    int buffer[2];
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open("dog.jpg",std::ios::binary | std::ios::in);
    outputFile.open("dogCopy.jpg",std::ios::binary | std::ios::out);

    while(inputFile.read((char *)&buffer, sizeof(buffer))) {
        outputFile.write((char *)&buffer, sizeof(buffer));
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
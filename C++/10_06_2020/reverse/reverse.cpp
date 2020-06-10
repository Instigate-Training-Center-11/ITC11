#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    const char *const inName = "input.txt";
    const char *const outName = "outputFile.txt";
    std::ofstream inputFile(inName);
    std::ofstream outputFile(outName);
    std::ifstream file(inName);
    std::string content;
    char ch;

    /* Create input.txt file whit content. */
    if (!inputFile.is_open()) {
        std::cerr << "Can't open the file!" << "\n";
    }
    inputFile << "Line first\nLine second\nLine third";
    inputFile.close();

    /* Get all characters and save all in a variable. */
    while(file.get(ch)) {
        content += ch;
    }

    /* Reverse content of input file and save the result in output file. */
    std::reverse(content.begin(), content.end());
    outputFile << content;
    
    return 0;
}
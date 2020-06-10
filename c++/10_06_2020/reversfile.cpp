#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* reverse string */
std::string reverseString(std::string& str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    for (int i = 0, j = length - 1; i < length/2; ++i, --j) {
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
    return str;
}
int main() {
    /* name and path source file "revers.txt" */
    std::ifstream file("revers.txt");
    std::string content;
    std::vector<std::string> numbers;
    /* name and path output file "output.txt" */
    std::ofstream out("output.txt");
    try {
        if(!file || !out) {
            throw "I can not open the file!\n";
        }
        /* selects lines of a file and writes to vector */
        while(file >> content){
            numbers.push_back(content);
        }
        /* writes in turn all the lines of the vector on the filet */
        for(int i = numbers.size() - 1; i >= 0; i--) {
            std::cout << numbers[i] << ' ';
            out << reverseString(numbers[i]) << "\n";

        }

        file.close();
        out.close();
    } catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
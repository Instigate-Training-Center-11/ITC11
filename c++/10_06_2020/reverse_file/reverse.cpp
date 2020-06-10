#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream in("1.txt");
    std::ofstream out("2.txt"/*, std::ofstream::ate*/);
    std::string txt = "";
    std::string line = "";

    /* Check if the file is open. */
    if (!in.is_open()) {
        std::cerr << "Can't open the file!" << std::endl;
        return -1;
    }

    /* Take content of the file */
    while (!in.eof()) {
        std::getline(in, line);
        txt = txt + "\n" + line;
    }

    /* Reverse string and write in the file */
    std::reverse(txt.begin(), txt.end());
    out << txt;
    std::cout << line << std ::endl;

    in.close();
    out.close();

    return 0;
}
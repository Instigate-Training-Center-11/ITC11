#include <iostream>
#include <fstream>
#include <string>

int main() {
    /* ifstream is a stream class to read from files */
    /* open 1.png file for input operation in binary mode */
    std::ifstream InF("1.png", std::ios::in | std::ios::binary);

    /* ofstream is a stream class to write on files */
    std::ofstream OutF;

    /* open 2.png file for output operation in binary mode */
    OutF.open("2.png", std::ios::out | std::ios::binary);

    /* Create a buffer by allocating memory */
    char* buffer = new char[1024];

    /* read data available in buffer */
    int data = InF.readsome(buffer, 1024);

    /* read from file, while reading data is greater then 0 */
    while (data > 0) {
        OutF.write(buffer, data);
        data = InF.readsome(buffer, 1024);
    }

    return 0;
}
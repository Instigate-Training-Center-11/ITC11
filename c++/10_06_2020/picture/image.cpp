#include <iostream>
#include <fstream>

int main() {
    int array[5];
    std::ifstream inpoto;
    std::ofstream outpoto;
    inpoto.open("horse.jg",std::ios::binary | std::ios::in);
    outpoto.open("horse_second.jpg",std::ios::binary | std::ios::out);

    if (!inpoto.is_open()) {
        std::cerr << "Can't open the poto!" << std::endl;
        return -1;
    }

    while(!inpoto.eof()) {
        inpoto.read((char *)&array, sizeof(array));
        outpoto.write((char *)&array, sizeof(array));
    }

    inpoto.close();
    outpoto.close();

    return 0;
}
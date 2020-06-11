#include <fstream>
#include <iostream>
int main() {
    std::ofstream out;
    std::ifstream in;
    int buff[5];
    in.open("birds.jpg", std::ios::in |std::ios::binary);
    out.open("birdsCp.jpg", std::ios::in |std::ios::binary);

    while(in.read((char*)&buff, sizeof(buff))) {
        out.write((char*)&buff, sizeof(buff));
    }
    in.close();
    out.close();
    return 0;
}


#include <iostream>
using namespace std;
#include <fstream>


int main() {
        ofstream ofs("newFailName.txt");
        std::ifstream ifs("failName.txt", ios::in | ios::ate);
        long size = ifs.tellg();
        char ch;

while(ifs) {
        ifs.seekg(--size);
        ifs.get(ch);
        if(-1 == size) {
               break;
        }
        ofs << ch;
}

return 0;
}
~    

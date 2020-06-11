#include <fstream> //open file for writing

int main(){
    std::ofstream myfile;
    std::ofstream o("3.txt");
    o<<"Hello world\n"<<std::endl;
    myfile.open("3.txt");
    myfile<<"Hellow world\n";
    myfile.close();
    return 0;
}

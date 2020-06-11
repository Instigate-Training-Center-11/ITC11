#include <iostream>
#include <fstream>
char caesarCypher(char p, int k){
  return (p+k)%256;
};
std::string cryptograph (std::string z,int step,int size){
    for (int i = 0; i < size; i++)
    {
        z[i]=caesarCypher(z[i],step);
    }
    return z;
    
};
std::string read(std::string fileName){

    std::ifstream input(fileName);
    std::string output;
    while (!input.eof())
    {
        input>>output;
    }
    return output;
    
}
int main(){
    //std::cout<<CaesarCypher('a',1);
    int a;
    std::cout<<"Enter number for encryption\n";
    std::cin>>a;
    std::string c="abc";
    std::string filename;
    std::cout<<"Enter your file's name\n";
    std::cin>>filename;
    std::string encrypt=cryptograph(read(filename),a,11);
    std::string decrypt=cryptograph(encrypt,256-a,11);
    std::cout<<"Encryption: "<<encrypt<<'\n'<<"Decryption: "<<decrypt<<'\n';
    return 0;
}
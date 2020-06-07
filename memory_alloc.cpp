#include <iostream>
 void swapp(int a, int b);
 void swappRef(int &a, int &b);
int main(){
    int a=145;
    int* b=NULL;
    b=&a;
    std::cout<<a<<'\n';
    std::cout<<b<<'\n'; //will print address of b
    std::cout<<*b<<'\n'; //will print 145
    int first=14;
    int second=15;
    std::cout<<"first after swapping\n"<<first<<'\n'<<"secoond after swapping\n"<<second<<'\n';
    swapp(first,second);
    std::cout<<"first and second after swapping with no &\n";
    std::cout<<first<<' '<<second<<'\n';
    swappRef(first,second);
    std::cout<<"first and second values after swapping with &\n";
    std::cout<<first<<" "<<second<<'\n';
    int* arr=new int[8];
    for(int i=0;i<8;i++){
        std::cout<<arr[i]<<'\n';
        std::cout<<arr+i<<'\n';//Here are the elements of array addreses with hexadecimal format
    }
    std::cout<<'\n';
    return 0;
}
void swapp(int a, int b){
  int temp=a;
  a=b;
  b=temp;
  std::cout<<a<<' '<<b<<'\n'; //this prints a and b values after swapping
}
void swappRef(int &a, int &b)
{
   int temp=a;
   a=b;
   b=temp;
}

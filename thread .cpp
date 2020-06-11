#include <thread>
#include <iostream>
#include <mutex>
std::mutex m;
void foo(int k){
    m.lock();
    for(int i=0;i<k;i++)
    {
        std::cout<<i<<' ';
    }
    m.unlock();
}
int main(){
    
    std::thread th1(foo,5);
    std::thread th2(foo,6);
    th1.join();
    th2.join();

    for (int i = 0; i < 3; i++)
    {
        std::cout<<i+1<<' ';
    }
    
    std::cout<<'\n';
    return 0;
}
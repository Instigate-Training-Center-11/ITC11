#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void threadMut() {
    m.lock();
    std::cout << "Hello" << std::endl;
    m.unlock();

    std::cout << "INSIDE THREAD" <<"\n";
}

void mutThread(int num) {
    m.lock();
    for (int i = 0; i < num; num++) {
        std::cout << "Hi" << std::endl;
    }
    m.unlock();

    for (int i = 0; i < num; num++) {
        std::cout << "Bye thread" << std::endl;
    }


}
int main() {
    std::thread th1(threadMut);
    std::thread th2(mutThread,5);
    th2.join();
    th1.join();

    return 0;
}


#include <iostream>

/*Declared and initialized var2 how global const variable*/
/*Which means that it is available in any part of the program but the value cannot be changed, it is stable*/
int const gConstVar = 1;

/*Declared and initialized var2 how global variable*/
/*Which means that it is available in any part of the program*/
int gVar = 2;

int main () {
    /*Declared and initialized constVar how const variable*/
    /*The value cannot be changed, it is stable*/
    int const constVar = 1;

    /*Declared and initialized lVar how local variable*/
    int lVar = 2;

    /*Declared and initialized sVar how static variable*/
    static int sVar = 2;

    /*Declared and initialized var and var1 variables at integer numbers*/
    /*They have in stack consecutive addresses in size of integer 4b*/
    int var = 5;
    int var1 = 8;

    /*Declared var variable at pointer*/
    int *p = &var;

    /*Declared var variable at reference*/
    int &v = var;

    /*In output we see that gConstVar, gVar, sVar have consecutive addresses in stack*/
    /*For example 0x00,0x04,0x08*/
    std::cout << "&gConstVar = " << &gConstVar << std::endl;
    std::cout << "&gVar = " << &gVar << std::endl;
    std::cout << "&sVar = " << &sVar << std::endl;

    /*In output we see that constVar, lVar have consecutive addresses in stack*/
    /*For example 0x00,0x04*/
    std::cout << "&lVar = " << &lVar << std::endl;
    std::cout << "&constVar = " << &constVar << std::endl;

    /*When a variable is declared as reference, it becomes an alternative name for an existing variable,
     because reverence occupies a variable address in memory.*/
    /*Then in both cases you will get the same address in some &var cases*/
    std::cout << "Addresses var and var1" << std::endl;
    std::cout << "&var = " << &var << std::endl;
    std::cout << "&var1 = " << &var1 << std::endl;
    std::cout << "Address &v variable" << std::endl;
    std::cout << "&v = " << &v << std::endl;

    /*Pointer has in stack own address and will keep the address var*/
    /*&var address var variable,p as a value holds the var address,&p address pointer p*/
    std::cout << "Addresses after pointer" << std::endl;
    std::cout << "&var = " << &var << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "&p = " << &p << std::endl;

    /*Declared a dynamic array*/
    int *a = new int[3];
    /*Print the addresses of the elements of the array, which are arranged in successive addresses in heap*/
    /*When we apply, they will give us the address of the first element of array*/
    /*After completing the case with the masses, the memory must be released*/
    std::cout << "Array elements addresses" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << (a+i) << std::endl;
    }

    return 0;
}


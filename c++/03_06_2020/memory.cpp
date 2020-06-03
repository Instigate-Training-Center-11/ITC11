#include <iostream>

/*
The function accepts 2 arguments. First of them is by value, and the other is by reference.
Inside this function, these 2 arguments are changed. At the end of the function, we print
the modified function arguments
*/
void foo(int aa, int &bb) {
    ++aa;
    aa += bb;
    ++bb;
    std::cout << aa << "\t" << bb << std::endl;
}

int main() {
    /*
    Declare 3 integer variables. These variables are located inthe stack and, let's assume,
    occupy the following addresses, respectively: 0x0000, 0x0004, 0x0008
    */
    int a = 10;
    int b = 20;
    int c = 30;

    /* 
    The addresses of these 3 variables will be displayed here. Respectively: 0x0000, 0x0004,
    0x0008. In fact, these are supposed addresses and the real addresses will be different.
    */
    std::cout << &a << "\t" << &b << "\t" << &c << std::endl;

    /*
    Declare 3 variables whit type is pointer integer and each of them takes up 8 bytes of
    memory: 0x0010, 0x0018, 0x0020. These variables are assigned the addresses of the
    above-mentioned variables.
    */
    int *A = &a;
    int *B = &b;
    int *C = &c;

    /*
    Since the type of A, B, C variables is pointer integer and they contain an address,
    the address of the a, b, c will be printed here
    */
    std::cout << A << "\t" << B << "\t" << C << std::endl;

    /*
    Using x, we will take the address of this variable, so here we will print the stack
    addresses where the A, B, C variables are located. The adresses will be folowing:
    &A = 0x0010, &B = 0x0018, &C = 0x0020.
    */
    std::cout << &A<< "\t" << &B << "\t" << &C << std::endl;

    /*
    With x, we have access from a given address obsessive. therefore, we get the value
    that is located under this address. *A -> 10, *b -> 20, *C -> 30
    */
    std::cout << *A<< "\t" << *B << "\t" << *C << std::endl;

    /*
    Variable b is assigned the contents of variable A. the contents of variable A can
    be obtained using *. And value b become 10 instead of 20.
    */
    b = *A;

    /*
    Creating a variable with the int& type that refers to the same address in the stack
    where the b variable is located. refp, b in -> 0x0004
    */
    int &refp = b;

    /* Add the content of address B as a 1. b and refp -> 11 */
    ++*B;

    /* After that, the value of refp will be equal to 11. */
    std::cout << refp << std::endl;

    /*
    Declaring a static array of length 5. This stack array will take up 20 bytes of memory.
    arr[0] -> 0x0028, arr[1] -> 0x002c, arr[2] -> 0x0030, arr[3] -> 0x0034, arr[5] -> 0x0038
    */
    int arr[] = {1, 2, 3, 4, 5};
    for (int  i = 0; i < 5; i++) {

        /*
        Use the loop to output the addresses of all elements of this arra
        arr[0] -> 0x0028, arr[1] -> 0x002c, arr[2] -> 0x0030, arr[3] -> 0x0034, arr[5] -> 0x0038
        */
        std::cout << arr + i << "\t";

        /*
        In this line, we take the contents of each stack cell that are array elements and output
        them. arr[0] -> 1, arr[1] -> 2, arr[2] -> 3, arr[3] -> 4, arr[5] -> 5
        */
        std::cout << *(arr + i) << "\t";

        /*
        All elements of the array are also output here.
        arr[0] -> 1, arr[1] -> 2, arr[2] -> 3, arr[3] -> 4, arr[5] -> 5
        */
        std::cout << arr[i] << std::endl;
    }

    /*
    Declares 2 integer variables that will be given arguments to the function.
    a1 adress is -> 0x003c, b1 adress is -> 0x0040,
    */
    int a1 = 5;
    int b1 = 15;

    /* Output these variables before calling the function. the result is a1 -> 5, b1 -> 15 */
    std::cout << a1 << "\t" << b1 << std::endl;

    /*
    When calling a function, the stack is divided into separate memory for this function,
    which can be called a frame. The first argument of the function will be copied to this
    frame in this adress: 0x0044, and second will not be copied, since function the second
    argument get by referens. Therefore, if the value of second arguments changes inside
    the function, this change will be saved after calling the function. That is, when we
    work with first argument of a function, we work with a copy of the original, and when
    we work with second argument of a function, in this case we do not have a copy, and we
    work with the original. Therefore, even after calling the function, if we print the
    second variable that was passed to the function as an argument, then it's value will
    already be changed. When the function ends, the frame that was passed to the function
    for its operation is removed from the stack. then the stack pointer moves back.
    */
    foo(a1, b1);

    /* Output these variables before calling the function. the result is a1 -> 5, b1 -> 16 */
    std::cout << a1 << "\t" << b1 << std::endl;

    return 0;
}
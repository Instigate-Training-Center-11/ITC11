#include <iostream>

/* Function prototype */
void fn(int, int &);

int main () {  
    /* Here are variables with their own type and value. */
    int a = 5;
    int* b1 = NULL;
    b1 = &a;
    int** b2 = NULL;
    b2 = &b1;
    int*** b3 = NULL;
    b3 = &b2;

    /*
    The variable b1, whit type pointer, is assigned the address of a (using this
    construction - &a). This means that, the variable b1 will not store a decimal
    number, but a hexadecimal address, where the variable a is stored. To take the
    value that is stored in this address, you can use this: *b1. You can also create
    a variable with type int** and this variable can take values only with type int*.
    This variable is my b2. In this example, b2 can only get the address of the
    variable b1, as long as b1 have int* type. b2 is the address of b1; *b2 is the
    inside of that address; but since the address stored inside b1, *b2 will return
    address of variable a, and only **b2 will give as inside of that address, which
    is the value of the variable a, i.e. 5.
    */
    std::cout << *b1 << "\n";   // 5
    std::cout << **b2 << "\n";  // 5
    std::cout << ***b3 << "\n"; // 5

    /* Here is declared a dynamic array, one-dimensional, with a length of 5. */
    int* d = new int[5];

    /*
    Use the loop to go through the array and output its elements. since the array
    is not initialized, the compiler will either assign the element 0, or whatever
    is currently in this address, when compiling.
    */
    for (int i = 0; i < 5; ++i) {
        /*
        Here you can output array elements that will be 0 or some value that will
        currently be located in this address.
        */
        std::cout << d[i] << "\n";
        /* Here the addresses of all elements will be output in hexadecimal format. */
        std::cout << d + i << "\n";
    }
    /*
    A two-dimensional array is declared that contains 3 elements, each of which is a 
    reference to a one-dimensional dynamic array.
    */
    int **ar =new int*[3];

    for (int i = 0; i < 3; i++) {
        ar[i] = new int[3];
    }

    /*
    This way you can output array elements, but since the array is not initialized 
    in this case, either zeros or the value that is in the data of the memory cell 
    are output.
    */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "ar: " << ar[i][j] << "\n";
        }
    }

    /*
    We declare integer variable var, as well as a variable of the 'int &' type.
    This variable must be initialized immediately after the declaration, since
    it does not have its own address space, in order to give it a default value,
    and then change it during the program. If the var variable is located, for
    example, in the 0x00 cell of the stack, then the ref variable will also 
    reference the same memory cell. This means, that with this path, we create 2
    names for 1 memory cell. This means that, we have access to this cell using 2
    variables. so if we change the value of 1 variable, then the value of 2
    variable will also change, because the memory they point to is the same.
    */
    int var = 2;
    int &ref = var;
    ++ref;

    /* Both variables will change. */
    std::cout << "ref: " << ref << "\n";  // 3
    std::cout << "var: " << var << "\n";  // 3

    /* Declaration 2 integer variables. */
    int var1 = 1;
    int var2 = 7;
    /* Function output will be 3 for var1 and 9 for var2 */
    fn(var1, var2); 
    /*
    The value of the declared variables after calling the function, that the
    second argument took by reference.
    */
    std::cout << "var1 from main: " << var1 << "\n";  // 1
    std::cout << "var2 from main: " << var2 << "\n";  // 9

    return 0;
}

/*
The first argument function gets by value, the second - by reference. The argument
by reference does not copy in the frame, that is defined for the function after it
is called. The second 'int &var2' argument refers to a variable var2 and they both
take up 1 memory cell in the stack. Therefore, after calling the function, the value
of the variable var2 changes, but the variable var1 does not change, because the variable
var1 is copied in the frame for the function and inside the function we work with a
copy of this variable, the original remains intact.
*/
void fn(int var1, int &var2) {
    var1 += 2;
    var2 += 2;
    std::cout << "var1 from function: " << var1 << "\n";
    std::cout << "var2 from function: " << var2 << "\n";
}
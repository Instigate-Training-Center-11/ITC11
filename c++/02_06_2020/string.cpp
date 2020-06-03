#include <iostream>

/*
    This function gets the parameter from the user and the reverseded it.
*/

char *reversString(char *str) {
    char *newStr = str;
    char  temp = '\0';
    char *firstStr = newStr - 1;
    char *lastStr = newStr;

    /* Find the end of the string */
    while (*lastStr) {
        ++lastStr;
    }

    /* Reverse it */
    while (lastStr-- > ++firstStr)
        {
        temp = *firstStr;
        *firstStr = *lastStr;
        *lastStr = temp;
    }

    return newStr;
}

int main() {

    /* Input size of string */
    int size = 0;
    std::cout << "Please enter size of string: ";
    std::cin >> size;

    /*
        This function is so,
        that nothing get in the way of entering the string
    */
    std::cin.ignore();

    /* Input the string */
    char *string = new char[size];
    std::cout << "Please enter a string: ";
    std::cin.getline(string, size);
    
    /* Output the string ant reversed string */
    std::cout << string << std::endl << reversString(string) << std::endl; 
    
    delete [] string;
    return 0;
}
#include <iostream>

/*
    This function gets the parameter from the user and the reverseded it.
*/
char *reversString(char *str) {
    char  temp = '\0';
    char *firstStr = str - 1;
    char *lastStr = str;

    /* Find the end of the string */
    while (*lastStr) {
        ++lastStr;
    }

    /* Reverse it */
    while (lastStr-- > ++firstStr) {
        temp = *firstStr;
        *firstStr = *lastStr;
        *lastStr = temp;
    }

    return str;
}

int main() {
    int size = 100;

    /* Input the string */
    char string[size];
    std::cout << "Please enter a string: ";
    std::cin.getline(string, size);
    
    /* Output the string ant reversed string */
    std::cout << string << std::endl;
    std::cout << reversString(string) << std::endl;

    return 0;
}
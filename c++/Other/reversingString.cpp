#include <iostream>

/* declare variables for calculate count of chars and for iterate*/
int count = 0;
int i = 0;

int main(int argc, const char * argv[]) {
    /* declare dynamic array of chars */
    char *ptrString = new char[20];
    /* input the string and to display it */
    std::cout << "Enter some word or string: " <<std::endl;
    std::cin >> ptrString;
    std::cout << ptrString << std::endl;
    /* calculate the length of char array || string until terminate symbol */
    while (ptrString[i] != '\0') {
        count++;
        i++;
    }
    /* swap elements of array. Firs element to end, second to end-1 ... */
    while (i < count/2) {
	char temp = ptrString[i];
        ptrString[i] = ptrString[count];
	ptrString[count] = temp;
        std::cout << ptrString[i] << std::endl;
        count--;
        i++;
}
    return 0;
}

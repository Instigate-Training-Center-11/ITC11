#include <iostream>
#include <algorithm>

/* function prototype to get ugly number */
int uglyNumber(int);
int checkType(int);

int main()
{
    int n = 0;
    std::cout << "\nTo get an ugly number, please, enter its term:  ";
    std::cin >> n;
    n = checkType(n);
    std::cout << "The ugly number is:  " << uglyNumber(n) << std::endl;
}

int uglyNumber(int n)
{
    int uglyNumArr[n];
    int num2 = 0;
    int num3 = 0;
    int num5 = 0;

    /* initialize multiples of 2, 3 and 5 */
    int multOf2 = 2;
    int multOf3 = 3;
    int multOf5 = 5;
    int uglyNum = 1;

    /* initialize ungly number */
    uglyNumArr[0] = 1;

    /* loop to find next ugly number */
    for (int i = 1; i < n; ++i)
    {
        uglyNum = std::min(std::min(multOf2, multOf3), multOf5);
        uglyNumArr[i] = uglyNum;

        if (uglyNum == multOf2)
        {
            ++num2;
            multOf2 = uglyNumArr[num2] * 2;
        }

        if (uglyNum == multOf3)
        {
            ++num3;
            multOf3 = uglyNumArr[num3] * 3;
        }

        if (uglyNum == multOf5) {
            ++num5;
            multOf5 = uglyNumArr[num5] * 5;
        }
    }
   return uglyNum;
}

int checkType(int input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "\nPlease enter integer type data: ";
        std::cin >> input;
    }

    return input;
}
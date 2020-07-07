#include <iostream>
#include "UglyNumbers.cpp"

int main()
{
  int index;
  cout << "Enter the index which ugly number need to find: " << endl;
  cin >> index;
  int number = getNthUglyNo(index);
  cout << "In this position is the ugly number " << number << endl;
  return 0;
}
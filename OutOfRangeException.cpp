#include <iostream>

int main () {
  int myarray[10];
  try
  {
    for (int n=0; n<10; n++) {
      if (n>10) {
          throw "Exeption msg - Out of range";
      myarray[n]= 5;
      }
    }
  }
  catch (int arr)
  {
    std::cout << "Exception: " << arr << std::endl;
  }
  return 0;
}
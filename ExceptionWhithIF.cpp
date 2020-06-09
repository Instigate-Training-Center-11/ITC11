#include <iostream>

int main() {
  try {
    int age = 15;
    if (age > 18) {
      std::cout << "All right, welcome";
    } else {
      throw 3333;
    }
  }
  catch (int e) {
    std::cout << "You must be at least 18 years old." << std::endl;
    std::cout << "Error number: " << e;  
  }
  return 0;
}

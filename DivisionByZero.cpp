#include <iostream>

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero :(";
   }
   return (a/b);
}
int main () {
   int x = 50;
   int y = 0;
   double d = 0;
 
   try {
      d = division(x, y);
      std::cout << d << std::endl;
   } catch (const char* string) {
      std::cerr << string << std::endl;
   }
   return 0;
}
#include <iostream>
using namespace std;

int min(int one, int two, int three)
{
  return (one < two && one < three) ? one : (two < three) ? two : three;
}

int getNthUglyNo(int n)
{
  int uglyNums[n];
  int two = 0; 
  int three = 0; 
  int five = 0;
  int i;
  int twoNextMult = 2;
  int threeNextMult = 3;
  int fiveNextMult = 5;
  int nextIndexUg = 1;
  uglyNums[0] = 1;

  for (i = 1; i < n; i++)
  {
    nextIndexUg = min(twoNextMult,
                      threeNextMult,
                      fiveNextMult);
    uglyNums[i] = nextIndexUg;
    if (nextIndexUg == twoNextMult)
    {
      two = two + 1; //two++
      twoNextMult = uglyNums[two] * 2;
    }
    if (nextIndexUg == threeNextMult)
    {
      three = three + 1;
      threeNextMult = uglyNums[three] * 3;
    }
    if (nextIndexUg == fiveNextMult)
    {
      five = five + 1;
      fiveNextMult = uglyNums[five] * 5;
    }
  }
  return nextIndexUg;
}
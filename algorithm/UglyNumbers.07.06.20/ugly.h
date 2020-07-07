#ifndef _UGLY_H_
#define _UGLY_H_

#include <iostream>
#include <thread>
#include <mutex>

long long int uglyNumberDynamic(int n, int& count);
long long int uglyNumberDynamicRecursion(int n, int& count, int f2, int f3, int f5);
long long int min(long long int num1, long long int num2);

#endif
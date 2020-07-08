#include <iostream>
#include <vector>
using namespace std;

vector<int> myVect;

int fibWithRec(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fibWithRec(n - 1) + fibWithRec(n - 2);
}

int fibWithoutRec(int n)
{
    if (n < myVect.size())
    {
        return myVect[n];
    }
    int f = fibWithoutRec(n - 1) + fibWithoutRec(n - 2);
    myVect.push_back(f);
    return f;
}

int main()
{
    int n;
    cout << "Add the index of searching fibonacci number " << endl;
    cin >> n;
    myVect.push_back(0);
    myVect.push_back(1);
    int result1 = fibWithRec(n);
    int result2 = fibWithoutRec(n);
    cout << "result after function with recursion is : " << result1 << endl;
    cout << "result after function without recursion is : " << result2 << endl;
    return 0;
}
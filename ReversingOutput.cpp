#include <fstream>
#include <algorithm>
using namespace std;

const int SIZE = 500;
char buf[ SIZE + 1];

int main() {
    /* ios::in opens the file for reading */
    /* ios::binary for bynary operatin for read or write */
    ifstream fin ("2.txt", ios::in | ios::binary);
    fin.read (buf, SIZE);
    /* gcount() returns the number of characters */
    int numOfChars = fin.gcount();
    fin.close();

    reverse (buf, buf + numOfChars);
    /* ios::out opens the file for writing */
    ofstream fout ("3.txt", ios::out | ios::binary);
    fout.write (buf, numOfChars);
    fout.close();
}
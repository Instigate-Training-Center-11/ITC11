#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  /* Create 3 text files */
  ofstream MyWriteFile1("FirstNumber.txt");
  ofstream MyWriteFile2("SecondNumber.txt");
  ofstream MyWriteFile3("ThirdNumber.txt");

  /* Write numbers to first file */
  for (int i = 0; i < 5; i++) {
    MyWriteFile1 << i;
  }

  /* Write symbols for ariphmetic operations to second file */
  char arrOperators[] = {
    '+',
    '-',
    '*',
    '/',
    '%'
  };
  for (int i = 0; i < 5; i++) {
    MyWriteFile2 << arrOperators[i];
  }

  /* Write numbers to 3rd file */
  for (int i = 5; i < 10; i++) {
    MyWriteFile3 << i;
  }

  /* Close files */
  MyWriteFile1.close();
  MyWriteFile2.close();
  MyWriteFile3.close();

  /* Create for files a text string, which is used to output the text file */
  string myText1;
  string myText2;
  string myText3;

  /* Read from the text file */
  ifstream MyReadFile1("FirstNumber.txt");
  ifstream MyReadFile2("SecondNumber.txt");
  ifstream MyReadFile3("ThirdNumber.txt");

  /* Use a while loop together with the getline() function to read the files line by line */

  while (getline(MyReadFile1, myText1)) {
    while (getline(MyReadFile3, myText3)) {
      while (getline(MyReadFile2, myText2)) {
        /* Use if/else to ralization ariphmetic operations */
        /* Use stoi to cast charachter to interger. To compile this file:  g++ AriphmeticOpFilesOutput.cpp --std=c++11 */
        if (myText2[2] = '+') {
          cout << myText1 << "+" << myText3 + "=";
          cout << stoi(myText1) + stoi(myText3) << endl;
        } else if (myText2[2] = '-') {
          cout << myText1 << "-" << myText3 + "=";
          cout << stoi(myText1) - stoi(myText3) << endl;
        } else if (myText2[2] = '*') {
          cout << myText1 << "*" << myText3 + "=";
          cout << stoi(myText1) * stoi(myText3) << endl;
        } else if (myText2[2] = '/') {
          cout << myText1 << "/" << myText3 + "=";
          cout << stoi(myText1) / stoi(myText3) << endl;
        } else {
          cout << myText1 << "%" << myText3 + "=";
          cout << stoi(myText1) % stoi(myText3) << endl;
        }
      }
      /* Clear the buffer */
      if (MyReadFile2.is_open()) {
        MyReadFile2.clear();
        MyReadFile2.seekg(0, ios::beg);
      }
    }
    /* Clear the buffer */
    if (MyReadFile3.is_open()) {
      MyReadFile3.clear();
      MyReadFile3.seekg(0, ios::beg);
    }
  }
  /* Close files */
  MyReadFile1.close();
  MyReadFile2.close();
  MyReadFile3.close();
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

	ifstream myfile1("1.txt");
	ifstream myfile2("2.txt");
	ifstream myfile3("3.txt");
	
	string line1;
	string line2;
	string line3;
	

	while(getline(myfile1, line1)) {
		while(getline(myfile3, line3)) {
			while(getline(myfile2, line2)) {
				if(line2[0] == '+') {
					cout << line1 << " + " << line3 << " = ";
					cout << stoi(line1) + stoi(line3) << endl;
				} else if(line2[0] == '-') {
                                        cout << line1 << " - " << line3 << " = ";
                                        cout << stoi(line1) - stoi(line3) << endl;
                                } else if(line2[0] == '*') {
                                        cout << line1 << " * " << line3 << " = ";
                                        cout << stoi(line1) * stoi(line3) << endl;
                                } else if(line2[0] == '/') {
                                        cout << line1 << " / " << line3 << " = ";
                                        cout << stoi(line1) / stoi(line3) << endl;
                                }
			}
			cout << endl;
			if(myfile2.is_open()) {
				myfile2.clear();
				myfile2.seekg(0, ios::beg);
			}
		}
                if(myfile3.is_open()) {
                                myfile3.clear();
                                myfile3.seekg(0, ios::beg);
                }
	}
	myfile1.close();
	myfile2.close();
	myfile3.close();
	return 0;
}


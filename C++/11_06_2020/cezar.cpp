#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encrypt(ifstream &ifs, ofstream &ofs, int &key) {
	char ch = '\0';

        while(ifs) {
                ifs.get(ch);
		cout << ch;
                if(((int)ch >= 97 && (int)ch <= 122) || ((int)ch >= 65 && (int)ch <= 90)) {
                        int i =key + (int)ch;
                        cout << (char)i;
                        ofs << (char)((int)ch + key);
                } else {
                        cout << ch;
                        ofs << ch;
                }
        }
}

void decrypt(ifstream &ifs, ofstream &ofs, int &key) {
	int dekey = key * (-1);
	encrypt(ifs, ofs, dekey);
}

bool arg(int argc) {
	if(4 != argc) {
		return false;
	}
	return true;
}

bool eOrD(char &ch) {
        if('e' == ch || 'd' == ch) {
                return true;;
        }
	return false;
}

int main (int argc, char *argv[]) {
	char ch ='\0';
	cout << "encrypt or decrypt e/d: ";
        cin >> ch;

	if(!arg(argc) || !eOrD(ch)) {
		return -1;
	}

        ifstream ifs(argv[1]);
	ofstream ofs(argv[3]);
	
	int key = stoi(argv[2]);

        if('e' == ch) {
                encrypt(ifs, ofs, key);
        } else if('d' == ch) {
                decrypt(ifs, ofs, key);
        }


	ofs.close();
	ifs.close();
	return 0;
}

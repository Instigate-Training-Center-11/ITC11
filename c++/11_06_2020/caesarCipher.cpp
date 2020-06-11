#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

void encrypt(std::ifstream &input,std::ofstream &output,int key);
void decrypt(std::ifstream &input,std::ofstream &output,int key);

int main (int argc,char* argv[]) {
	std::ifstream input(argv[1]);
	int key = atoi(argv[2]);
	std::ofstream output(argv[3]);
	int n = 0;
	try {
		if (4 != argc) {
			throw "lacking main arguments";
		}
		std::cout << "encrypt Enter 1\ndecrypt Enter 2\ninput number ->";
		std::cin >> n;
		switch (n) {
		case 1:
			encrypt(input,output,key);
			break;
		case 2:
			decrypt(input,output,key);
			break;
		default:
			std::cout<<"Invalid options\n";
			break;
		}
	} catch (const char* exception) {
		std::cerr << "Error: " << exception << '\n';
	}

	input.close();
	output.close();

	return 0;
}

void encrypt(std::ifstream &input,std::ofstream &output,int key) {
	char c;
	while (input.get(c)) {
		if (c >= 'a' && c <= 'z') {
			output << (char)((c - 'a' + key) % 26 + 'a');
		}
		else if (c >= 'A' && c <= 'Z') {
			output << (char)((c - 'A' + key) % 26 + 'A') ;
		}
		else output << c;
	}
}

void decrypt(std::ifstream &input,std::ofstream &output,int key) {
	char c;
	while (input.get(c)) {
		if (c >= 'a' && c <= 'z') {
			(char)('z' - ('z' - c + key) % 26 );
			output << (char)('z' - ('z' - c + key) % 26 );
		}
		else if (c >= 'A' && c <= 'Z') {
			output << (char)('z' - ('z' - c + key) % 26 );
		}
		else output << c;
	}
}

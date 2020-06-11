#include <iostream>
#include <fstream>

/* Encript or decript files */
std::string cript(std::string str, int key, int en_de);

/* Read and write from files */
void stream(char file_in[], char file_out[], int key, int en_de);

int main(int argc, char* argv[]) {
	int answer = 0;
	int key = 0;

	std::cout << "Please insert key: ";
	std::cin >> key;
	std::cout << "For encript from file_2 to file_1 insert: 0" << std::endl;
	std::cout << "For decript from file_1 to file_2 insert: 1" << std::endl;
	std::cin >> answer;

	/* verification for input */
	while ((std::cin.fail() | answer < 0 | answer > 1)) {
		std::cout << "Please insert 0 or 1: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> answer;
    }

	if (0 == answer) {
		stream(argv[2], argv[1], key, 1);
	} else {
		stream(argv[1], argv[2], key, 0);
	}

	return 0;
}

std::string cript(std::string str, int key, int en_de) {
  int asci_2 = 0;
  if (0 == en_de) {
	for (int i = 0; i < str.size(); ++i) {
		asci_2 = (int)str[i];
		asci_2 += key;
		if (asci_2 <= 126) {
			str[i] = (char)asci_2;
		} else {
			asci_2 = 31 + (asci_2 - 126);
			str[i] = (char)asci_2;
		}
	}
  } else {
	  for (int i = 0; i < str.size(); ++i) {
		asci_2 = (int)str[i];
		asci_2 -= key;
		if (asci_2 >= 32) {
			str[i] = (char)asci_2;
		} else {
			asci_2 = 127 - (32 - asci_2);
			str[i] = (char)asci_2;
		}
	}
  }
  return str;
}

void stream(char file_in[], char file_out[], int key, int en_de) {
	std::fstream in;
	std::fstream out;
	in.open(file_in);
	out.open(file_out, std::ios::app);
	std::string file_str = "";

	while (!in.eof()){
     std::getline (in,file_str);
	 out << cript(file_str, key, en_de);
    }
}
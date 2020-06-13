#include <iostream>
#include <fstream>
#include <string>

void copy(char[]);

int main(int argc, char *argv[]) {
	if (argc != 2) {
        std::cout << "Please insert path of image as argument main function!" << std::endl;
        std::cout << "Good Bye!" << std::endl;
        exit(1);
    }

	copy(argv[1]);

	return 0;
}

void copy(char name[]) {
	std::string copy_name = "copy_";
	int i = 0;
	while(name[i] != '\0') {
		copy_name += name[i];
		++i;
	}
	std::ofstream(copy_name, std::ios::binary) << std::ifstream(name, std::ios::binary).rdbuf();
}
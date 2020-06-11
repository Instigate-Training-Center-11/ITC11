#include <iostream>
#include <fstream>

int main() {
	std::ofstream("copy_c++.jpg", std::ios::binary) << std::ifstream("c++.jpg", std::ios::binary).rdbuf();
	return 0;
}
#include <iostream>
#include <fstream>

int main() {
	/* name and path output file "output.txt" */
	std::ofstream fileout("copy.jpg");
	/* name and path source file "sours.jpg */
	std::ifstream fin("sours.jpg",std::ios::binary);
	try {
        if(!fileout || !fin) {
            throw "I can not open the file!\n";
        }
		char ch;
		while(fin.read((char *)&ch,sizeof(ch))) {
			fileout.write((char *)&ch,sizeof(ch));
    	}
		std::ofstream("copy.jpg", std::ios::binary) << std::ifstream("sours.jpg", std::ios::binary).rdbuf();
		fileout.close();
	} catch (const char* exception) {
    	std::cerr << "Error: " << exception << '\n';
    }

	return 0;
}
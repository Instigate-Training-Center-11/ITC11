#include <iostream>
using namespace std;
#include <fstream>

int main ()
{
	char *buffer;
	long size;
	ifstream file ("img.jpg",ios::in|ios::binary|ios::ate);
	size = file.tellg();
	file.seekg (0,ios::beg);
	buffer = new char [size];
	file.read (buffer,size);
	ofstream ofs("newImgName.jpg");
	for(int i = 0; i < size; ++i) {
		ofs << buffer[i];
	}
	file.close();
	ofs.close();
	delete[] buffer;
	return 0;
}

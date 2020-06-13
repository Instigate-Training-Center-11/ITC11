#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

void reverse(char[], char[]);

void my_reverse(std::string);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Please insert paths of two files as arguments main function!" << std::endl;
        std::cout << "Good Bye!" << std::endl;
        exit(1);
    }

    reverse(argv[1], argv[2]);

    return 0;
}

void reverse(char input[], char output[]) {
    std::fstream in;
    std::fstream out;
    in.open(input);
    out.open(output);

    std::string str = "";

    if (in.fail() || out.fail()) {
        std::cout<<"No such file or directory!\n";
	    exit(1);
    }

    while (!in.eof()) {
        getline(in, str);
        /* #include <bits/stdc++.h> reverse function */
        // reverse(str.begin(), str.end());

        /* My function for reverse */
        my_reverse(str);

        out << str;
        out << '\n';
    }

    in.close();
    out.close();
}

void my_reverse(std::string str) {
    for (int i = 0, j = (str.size() - 1); i < str.size() / 2; ++i, --j) {
        str[i] ^= str[j] ^= str[i] ^= str[j];
    }
}
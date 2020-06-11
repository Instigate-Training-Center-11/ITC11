#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    const char* const fileName = "2.txt" ;
    
    string text ;

    /* read the characters in the file into the string */
    {
     ifstream file(fileName) ; // default mode is text, input
        char c ;
        while( file.get(c) ) // for each char, including white spaces
            text += c ; // append to string
    }

    /* reverse the text of string */
    reverse( text.begin(), text.end() ) ;

    /* write the reversed string into the another file */ 
    
    {
        ofstream file(fileName) ; // default mode is text, output, truncate
        file << text ;
    }


    
}

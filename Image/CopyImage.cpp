#include <fstream>
#include <iterator>
#include <algorithm>

int main()
{
    std::ifstream originalFile( "IMG_20180730_144207.jpg", std::ios::binary );
    std::ofstream copyFile( "NewVersion.jpg", std::ios::binary );

    std::copy( 
        std::istreambuf_iterator<char>(originalFile), 
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(copyFile));
}
#include <iostream> 

int main() {
    int rows = 2; 
    int coloms=3; 
    int addition[2][3];
    int subtract[2][3];
    int a[2][3] = {{4,5,6}, {7,8,9}};
    int b[2][3] = {{7,8,9}, {4,5,6}};

/* addition of matrix */
    for(int i=0;i<rows;++i) {
        for(int j=0;j<coloms;++j) {
            addition[i][j]=a[i][j]+b[i][j];
        }
    }
    std::cout << "Sum of the two matrices is:" << std::endl;    
    for(int i=0; i<rows; ++i) {   
        for(int j=0; j<coloms; ++j){
            std::cout << addition[i][j] << " ";
    }
        std::cout << std::endl;
}
/* subtraction of matrix */
for(int i=0;i<rows;++i){
        for(int j=0;j<coloms;++j){
            subtract[i][j]=a[i][j]-b[i][j];
        }
    }
    std::cout << "Subtraction of the two matrices is:" << std::endl;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<coloms; ++j){
            std::cout << subtract[i][j] << " ";
    }
        std::cout << std::endl;
}
    return 0;
}
   

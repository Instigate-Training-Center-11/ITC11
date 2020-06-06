#include <iostream>
#include <cstdlib>

int main(){
int row1,row2,col1,col2;
std::cout<<"Enter the first matrixes rows\n";
std::cin>>row1;
std::cout<<"Enter the first matrixes columns\n";
std::cin>>col1;
std::cout<<"Enter the second matrices rows\n";
std::cin>>row2;
std::cout<<"Enter the second matrices columns\n";
std::cin>>col2;
int a[row1][col1];
int b[row2][col2];
int c[row1][col2];
for(int i=0;i<row1;i++){
    for (int j = 0; j < col1; j++)
    {
        a[i][j]=rand()%10;//get [0,9] interval value
    }
    
}
for(int i=0; i<row2; i++){
    for (int j = 0; j < col2; j++)
    {
       b[i][j]=rand() %10;
    }
    
}
if(col1!=row2){
    std::cout<<"You can't mulriplicate this two matrices"<<'\n';
}
else
{
    std::cout<<"The first matrxi is \n";
    for(int i=0;i<row1;i++){
        for (int j=0;j<col1;j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<"The second matrix is \n";
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            std::cout<<b[i][j]<<" ";
        }
      std::cout<<'\n';
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; i < col2; i++)
        {
            c[i][j]=0;
            for(int k=0;k<row2;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
        
    }
    for(int i=0;i<row1;i++){
        for (int j = 0; j < col2; j++)
        {
            std::cout<<c[i][j]<<" ";
        }
        std::cout<<'\n';
        
    }
    
}
 
  return 0;  
}

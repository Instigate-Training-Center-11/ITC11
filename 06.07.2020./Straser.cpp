#include <iostream>
using namespace std;

class StrasAlg
{
    int i;
    int j;
    int first[2][2];
    int second[2][2];
    int third[2][2];
    int p1, p2, p3, p4, p5, p6, p7;

public:
    StrasAlg()
    {
      p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                first[i][j] = 0;
                second[i][j] = 0;
                third[i][j] = 0;
            }
        }
    }

    void inputing()
    {
        cout << "Matrix 1 : " << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cin >> first[i][j];
            }
        }
        cout << "Matrix 2 : " << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cin >> second[i][j];
            }
        }
    }

    void calculate()
    {
        p1 = (first[0][0] + first[1][1]) * (second[0][0] + second[1][1]);
        p2 = (first[1][0] + first[1][1]) * second[0][0];
        p3 = first[0][0] * (second[0][1] - second[1][1]);
        p4 = first[1][1] * (second[1][0] - second[0][0]);
        p5 = (first[0][0] + first[0][1]) * second[1][1];
        p6 = (first[1][0] - first[0][0]) * (second[0][0] + second[0][1]);
        p7 = (first[0][1] - first[1][1]) * (second[1][0] + second[1][1]);
        third[0][0] = p1 + p4 + -p5 + p7;
        third[0][1] = p3 + p5;
        third[1][0] = p2 + p4;
        third[1][1] = p1 + p3 - p2 + p6;
    }

    void display()
    {
        cout << "Resultant Matrix : " << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << third[i][j] << "\t";
            }
            cout << endl;
        }
    }
};


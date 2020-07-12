#include <iostream>
#include <string>
#include <vector>

std::vector<char> vecForDiff;

void display(std::vector<char>)
{
    for (int i = 0; i < vecForDiff.size(); i++)
    {
        std::cout << vecForDiff[i];
    }
}

void move(std::string str1, std::string str2, int i)
{
    vecForDiff.push_back('-');
    vecForDiff.push_back(str1[i]);
    vecForDiff.push_back('+');
    vecForDiff.push_back(str2[i]);
}

void compare(std::string str1, std::string str2)
{
    if (str1 == str2)
    {
        std::cout << "The strings are equals " << std::endl;
    }
    else
    {
        std::cout << "The strings have differents " << std::endl;

        if (str1.size() >= str2.size())
        {
            for (int i = 0; i < str1.size(); i++)
            {
                if (str1[i] == str2[i])
                {
                    vecForDiff.push_back(str1[i]);
                }
                else if (str1[i] != str2[i] && i < str2.size())
                {
                    move(str1, str2, i);
                }
                else
                {
                    vecForDiff.push_back('-');
                    vecForDiff.push_back(str1[i]);
                }
            }
        }
        else if (str1.size() < str2.size())
        {
            for (int i = 0; i < str2.size(); i++)
            {

                if (str1[i] == str2[i])
                {
                    vecForDiff.push_back(str1[i]);
                }
                else if (str1[i] != str2[i] && i < str1.size())
                {
                    move(str1, str2, i);
                }
                else
                {
                    vecForDiff.push_back('+');
                    vecForDiff.push_back(str2[i]);
                }
            }
        }
    }
}
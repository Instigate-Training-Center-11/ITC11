# include<stdio.h> 
#include <iostream>
# define MAX_SIZE 100 

void _print(int pos, int n, int open, int close);

// Wrapper over _printParenthesis() 
void print(int n)
{
	if (n > 0)
		_print(0, n, 0, 0);
	return;
}

void _print(int pos, int n, int open, int close)
{
	static char str[MAX_SIZE];

	if (close == n)
	{
		printf("%s \n", str);
		return;
	}
	else
	{
		if (open > close)
		{
			str[pos] = ')';
			_print(pos + 1, n, open, close + 1);
		}

		if (open < n)
		{
			str[pos] = '(';
			_print(pos + 1, n, open + 1, close);
		}
	}
}

int main()
{
	int n;
	std::cout << "Enter the count of brackets couples\n";
	std::cin >> n;
	std::cout << '\n';
	print(n);
	getchar();
	return 0;
}
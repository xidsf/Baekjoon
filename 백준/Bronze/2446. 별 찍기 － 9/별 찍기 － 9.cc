#include <iostream>
using namespace std;

int main()
{
    int cnt;
	cin >> cnt;
	for (int  i = 0; i < cnt; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = i; j < cnt; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < cnt - i - 1; j++)
		{
			cout << "*";
		}cout << "\n";
	}
	for (int i = cnt - 2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = i; j < cnt; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < cnt - i - 1; j++)
		{
			cout << "*";
		}cout << "\n";
	}

    return 0;
}
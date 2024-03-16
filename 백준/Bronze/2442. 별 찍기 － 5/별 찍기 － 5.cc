#include <iostream>
using namespace std;

int main()
{
    int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt ; i++)
	{
		for (int j = 0; j < cnt - i; j++)
		{
			cout << " ";
		}
		for (int j = cnt - i; j < cnt; j++)
		{
			cout << "*";
		}
		for (int j = cnt - i + 1; j < cnt; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

    return 0;
}
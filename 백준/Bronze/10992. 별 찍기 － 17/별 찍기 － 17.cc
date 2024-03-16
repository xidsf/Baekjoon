#include <iostream>
using namespace std;

int main()
{
    int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
	{
		if (i == cnt)
		{
			for (int j = 0; j < 2 * cnt - 1; j++)
			{
				cout << "*";
			}
		}
		else
		{
			for (int j = 1; j <= cnt - i ; j++)
			{
				cout << " ";
			}
			cout << "*";
			for (int j = 0; j < (i - 1) * 2 - 1; j++)
			{
				cout << " ";
			}
			if(i != 1) cout << "*";
			cout << "\n";
		}
	}

    return 0;
}
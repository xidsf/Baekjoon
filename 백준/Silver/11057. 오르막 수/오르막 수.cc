#include <iostream>
using namespace std;

long long prevCache[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
long long prevTemp = 55;

long long cache[10];
long long cachetemp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;

	if (input == 1)
	{
		cout << 10;
		return 0;
	}
	else if(input == 2)
	{
		cout << 55;
		return 0;
	}

	for (int i = 2; i < input; i++)
	{
		int temp = 0;
		for (int j = 0; j < 10; j++)
		{
			temp += prevCache[j];
			cache[j] = temp;
		}

		cachetemp = 0;
		for (int j = 0; j < 10; j++)
		{
			cachetemp += cache[j];
			cachetemp = cachetemp;
		}

		for (int j = 0; j < 10; j++)
		{
			cache[j] = cache[j] % 10007;
			prevCache[j] = cache[j];
		}
		cachetemp = cachetemp % 10007;
		prevTemp = cachetemp;
	}

	cout << cachetemp;

	return 0;
}
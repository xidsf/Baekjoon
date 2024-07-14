#include <iostream>
using namespace std;

long long cache[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cache[0] = 1;
	cache[1] = 2;
	cache[2] = 4;
	for (int i = 3; i < 15; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
	}

	int length;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		int input;
		cin >> input;
		cout << cache[input - 1] << "\n";
	}

	return 0;
}
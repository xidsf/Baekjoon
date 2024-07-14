#include <iostream>
using namespace std;

long long cache[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cache[0] = 1;
	cache[1] = 2;
	
	for (int i = 2; i < 1001; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
		cache[i] = cache[i] % 10007;
	}

	int input;

	cin >> input;
	cout << cache[input - 1];

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, reward;
	cin >> a >> b >> c;
	if (a == b && b == c)
	{
		reward = (a * 1000) + 10000;
	}
	else if (a == b || a == c)
	{
		reward = 1000 + a * 100;
	}
	else if (b == c)
	{
		reward = 1000 + b * 100;
	}
	else if (a > b)
	{
		if (a > c) reward = a * 100;
		else reward = c * 100;
	}
	else
	{
		if (b > c) reward = b * 100;
		else reward = c * 100;
	}
	cout << reward;
	return 0;
}
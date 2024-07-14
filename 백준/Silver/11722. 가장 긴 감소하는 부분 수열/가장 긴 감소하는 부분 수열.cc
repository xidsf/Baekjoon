#include <iostream>
#include <string>
using namespace std;

int arr[1001];
int cache[1001] = { 0, };
int length;
int ans = 1;

int maxLength = 0;

int dp(int index)
{
	if (index >= length)
	{
		return 0;
	}
	if (cache[index] != 0)
	{
		return cache[index];
	}

	cache[index] = 1;

	for (int i = index + 1; i < length; i++)
	{
		if (arr[i] < arr[index])
		{
			int temp = 1 + dp(i);
			if (cache[index] < temp)
			{
				cache[index] = temp;
			}
		}
	}

	return cache[index];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> length;

	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < length; i++)
	{
		dp(i);
	}

	for (int i = 0; i < length; i++)
	{
		if (maxLength < cache[i])
		{
			maxLength = cache[i];
		}
	}

	cout << maxLength;

	return 0;
}
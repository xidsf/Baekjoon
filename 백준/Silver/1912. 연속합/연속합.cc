#include <iostream>
#include <string>
using namespace std;

int length;
int arr[100001];
int cache[100001];


void SetCache()
{
	for (int i = length - 1; i >= 0; i--)
	{
		int temp;
		temp = arr[i] + cache[i + 1];
		if (temp > arr[i])
		{
			cache[i] = temp;
		}
	}
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
		cache[i] = arr[i];
	}

	SetCache();

	int maxValue = -1001;
	for (int i = 0; i < length; i++)
	{
		if (maxValue < cache[i])
		{
			maxValue = cache[i];
		}
	}

	cout << maxValue;

	return 0;
}
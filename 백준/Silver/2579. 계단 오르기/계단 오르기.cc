#include <iostream>
#include <string>
using namespace std;

int length;
int arr[301];
int cache[301] = { 0, };

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

	cache[0] = arr[0];
	cache[1] = arr[0] + arr[1];
	cache[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for(int i = 3; i < length; i++) 
	{ 
		cache[i] = max(cache[i - 2] + arr[i], arr[i - 1] + arr[i] + cache[i - 3]); 
	}

	cout << cache[length - 1];


	return 0;
}
#include <iostream>
using namespace std;


int main()
{
	int arr[10] = { 0, };
	int result = 1;
	int temp;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		result *= temp;
	}

	for (int i = 1; result >= i ; i *= 10)
	{
		temp = (result / i) % 10;
		arr[temp]++;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}
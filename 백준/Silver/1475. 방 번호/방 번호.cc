#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	int temp;
	int arr[10] = { 0, };
	for (int i = 1; input >= i; i *= 10)
	{
		temp = (input / i) % 10;
		arr[temp]++;
	}

	arr[6] += arr[9];
	if (arr[6] % 2 == 1) arr[6]++;
	arr[6] /= 2;
	temp = 0;
	for (int i = 0; i < 9; i++)
	{
		if (temp < arr[i]) temp = arr[i];
	}
	cout << temp;
	return 0;
}

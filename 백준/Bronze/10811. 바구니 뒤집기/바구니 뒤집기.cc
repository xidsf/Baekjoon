#include <iostream>
using namespace std;

int main()
{
	int *arr;
	int N, cnt;
	int a, b, convert, temp;
	cin >> N >> cnt;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}

	for (int i = 0; i < cnt; i++)
	{
		cin >> a >> b;
		convert = (b - a) / 2;
		convert++;
		for (int j = 0; j < convert; j++)
		{
			temp = arr[a - 1 + j];
			arr[a - 1 + j] = arr[b - 1 - j];
			arr[b - 1 - j] = temp;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	delete[]arr;
	return 0;
}
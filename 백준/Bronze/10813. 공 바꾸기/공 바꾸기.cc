#include <iostream>
using namespace std;

int main()
{
	int N, M, temp;
	int *arr;
	cin >> N >> M;
	arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}
	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		temp = arr[a - 1];
		arr[a - 1] = arr[b - 1];
		arr[b - 1] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	delete[]arr;
	return 0;
}
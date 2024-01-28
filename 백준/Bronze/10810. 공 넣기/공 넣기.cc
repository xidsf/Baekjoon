#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int *arr;
	cin >> N >> M;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
	}
	int first, last, num;
	for (int i = 0; i < M; i++)
	{
		cin >> first >> last >> num;
		for (int j = first - 1; j <= last - 1; j++)
		{
			arr[j] = num;
		}
	}
	for (int i = 0; i < N; i++) cout << arr[i] << " ";

	delete[] arr;
	return 0;
}
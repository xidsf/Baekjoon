#include <iostream>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size, cnt;
	cin >> size >> cnt;
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	int** prefixSum = new int* [size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		prefixSum[i] = new int[size + 1];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < size + 1; i++)
	{
		prefixSum[i][0] = 0;
		prefixSum[0][i] = 0;
	}


	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + arr[i - 1][j - 1];
		}
	}

	int x1, y1, x2, y2;

	for (int i = 0; i < cnt; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;

		cout << prefixSum[x2][y2] - prefixSum[x2][y1] - prefixSum[x1][y2] + prefixSum[x1][y1] << "\n";
	}
	return 0;
}
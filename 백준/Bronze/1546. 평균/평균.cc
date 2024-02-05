#include <iostream>
using namespace std;

int main()
{
	double *arr;
	int N;
	double sum = 0;
	int high = 0;
	cin >> N;
	arr = new double[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] > high) high = arr[i];
	}
	for (int i = 0 ;i < N; i++)
	{
		arr[i] = arr[i] / high * 100;
	}
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	cout << fixed;
	cout.precision(6);
	cout << sum / double(N);

	delete[]arr;
	return 0;
}
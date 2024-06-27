#include <iostream>
using namespace std;


int main()
{
	int cnt;
	cin >> cnt;
	double* arr = new double[cnt];

	double max = 0;
	int maxidx = 0;

	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			maxidx = i;
		}
	}
	double average = 0;
	for (int i = 0; i < cnt; i++)
	{
		average += (arr[i] / max) * 100;
	}

	average = average / cnt;
	cout << average;
	return 0;
}
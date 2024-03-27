#include <iostream>
using namespace std;

int main()
{
    int cnt, max, room = 0;
	cin >> cnt >> max;

	int arr[6][2] = { 0, };

	int gender, grade;
	for (int i = 0; i < cnt; i++)
	{
		cin >> gender >> grade;
		arr[grade - 1][gender]++;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (arr[i][j] % max > 0) room += arr[i][j] / max + 1;
			else room += arr[i][j] / max;
		}
	}
	cout << room;
    return 0;
}
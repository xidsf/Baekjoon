#include <iostream>
using namespace std;

int map[2187][2187];
int first = 0, second = 0, third = 0;

void Cut(int x, int y, int len)
{
	int temp;
	for (int i = y; i < len + y; i++)
	{
		for (int j = x; j < len + x; j++)
		{
			if (map[i][j] != map[y][x])
			{
				temp = len / 3;
				Cut(x, y, len / 3); //1
				Cut(x + temp, y, len / 3); //2
				Cut(x + temp * 2, y, len / 3); //3

				Cut(x, y + temp, len / 3); //4
				Cut(x + temp, y + temp, len / 3); //5
				Cut(x + temp * 2, y + temp, len / 3); //6

				Cut(x, y + temp * 2, len / 3); //7
				Cut(x + temp, y + temp * 2, len / 3); //8
				Cut(x + temp * 2, y + temp * 2, len / 3); //9
				return;
			}
		}
	}
	if (map[y][x] == -1) first++;
	else if (map[y][x] == 0) second++;
	else third++;

}

int main()
{
	int l;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cin >> map[i][j];
		}
	}

	Cut(0, 0, l);

	cout << first << "\n" << second << "\n" << third;

	return 0;
}
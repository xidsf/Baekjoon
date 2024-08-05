#include <iostream>
using namespace std;

int video[64][64];

void Func(int size, int x, int y)
{
	int bit = video[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (video[i][j] != bit)
			{
				cout << "(";
				Func(size / 2, x, y);
				Func(size / 2, x + size / 2, y);
				Func(size / 2, x, y + size / 2);
				Func(size / 2, x + size / 2, y + size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << bit;

}

int main()
{
	int videoSize;
	cin >> videoSize;

	for (int i = 0; i < videoSize; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < videoSize; j++)
		{
			video[i][j] = s[j] - '0';
		}
	}

	Func(videoSize, 0, 0);


	return 0;
}
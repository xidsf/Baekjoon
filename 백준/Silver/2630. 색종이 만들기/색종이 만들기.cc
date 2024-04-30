#include <iostream>
using namespace std;

int map[128][128];
int white = 0, blue = 0;
int len;

void Cut(int x , int y, int len)
{
	for (int i = y; i < (y + len); i++)
	{
		for (int j = x; j < (x + len); j++)
		{
			if (map[y][x] != map[i][j])
			{				
				Cut(x , y, len / 2); //좌상
				Cut(x + len / 2 , y, len / 2); //우상
				Cut(x, y + len / 2 , len / 2); //좌하
				Cut(x + len / 2 , y + len / 2, len / 2); //우하
				return;
			}
		}
	}
	if (map[y][x] == 0) white++;
	else blue++;
}


int main()
{
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cin >> map[i][j];
		}
	}
	
	Cut(0, 0, len);
	cout << white << "\n" << blue;

	return 0;
}
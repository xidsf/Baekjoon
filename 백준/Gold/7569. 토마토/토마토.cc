#include <iostream>
#include <queue>
using namespace std;

enum Tomato {
	None = -1, Normal, Riped
};

typedef struct Point {
	int h, row, column;
};

int map[100][100][100];
bool visited[100][100][100];
Point dir[6] = { {1, 0, 0}, {0, 1, 0},{0, 0, 1} ,{-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };
int g_Row, g_Col, g_Height;


int main()
{
	int day = -1, qSize;
	Point current, temp;
	queue<Point> Q;
	cin >> g_Col >> g_Row >> g_Height;
	for (int i = 0; i < g_Height; i++)
	{
		for (int j = 0; j < g_Row; j++)
		{
			for (int k = 0; k < g_Col; k++)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == Riped) Q.push({i, j, k});
			}
		}
	}

	while (!Q.empty())
	{
		qSize = Q.size();
		for (int i = 0; i < qSize; i++)
		{
			current = Q.front();
			Q.pop();
			map[current.h][current.row][current.column] = Riped;
			for (int j = 0; j < 6; j++)
			{
				temp.row = current.row + dir[j].row;
				temp.column = current.column + dir[j].column;
				temp.h = current.h + dir[j].h;

				if (temp.row >= 0 && temp.column >= 0 && temp.h >= 0)
				{
					if (temp.row < g_Row && temp.column < g_Col && temp.h < g_Height)
					{
						if (map[temp.h][temp.row][temp.column] == Normal && !visited[temp.h][temp.row][temp.column])
						{
							Q.push(temp);
							visited[temp.h][temp.row][temp.column] = true;
						}
					}
				}
			}
		}
		day++;
	}

	for (int i = 0; i < g_Height; i++)
	{
		for (int j = 0; j < g_Row; j++)
		{
			for (int k = 0; k < g_Col; k++)
			{
				if (map[i][j][k] == Normal)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << day;
	return 0;
}
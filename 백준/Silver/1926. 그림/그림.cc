#include <iostream>
#include <queue>
using namespace std;

bool map[500][500];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int g_Row, g_Col;
int picCount = 0, max_Size = 0;


void Picture(int row, int col)
{
	pair<int, int> current;
	pair<int, int> temp;
	queue<pair<int, int>> q;
	int size = 0;
	q.push(make_pair(row, col));
	map[row][col] = 0; 
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		size++;
		for (int i = 0; i < 4; i++)
		{
			temp = make_pair(current.first + dir[i][0], current.second + dir[i][1]);
			if (temp.first < g_Row && temp.second < g_Col)
			{
				if (temp.first >= 0 && temp.second >= 0)
				{
					if (map[temp.first][temp.second] == 1)
					{
						q.push(temp);
						map[temp.first][temp.second] = 0;
					}
				}
			}
		}
	}
	picCount++;

	if (size > max_Size) max_Size = size;
}

int main()
{
	cin >> g_Row >>g_Col;

	for (int i = 0; i < g_Row; i++)
	{
		for (int j = 0; j < g_Col; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < g_Row; i++)
	{
		for (int j = 0; j < g_Col; j++)
		{
			if (map[i][j] == 1)
			{
				Picture(i, j);
			}
		}
	}

	cout << picCount << "\n" << max_Size;

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

enum Tomato {
	None = -1, Normal, Riped
};

int map[1000][1000];
bool visited[1000][1000];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int g_Row, g_Col;


int main()
{
	int day = -1, qSize;
	pair<int, int> current, temp;
	queue<pair<int, int>> Q;
	cin >> g_Col >> g_Row;

	for (int i = 0; i < g_Row; i++)
	{
		for (int j = 0; j < g_Col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == Riped) Q.push(make_pair(i, j));
		}
	}

	while (!Q.empty())
	{
		qSize = Q.size();
		for (int i = 0; i < qSize; i++)
		{
			current = Q.front();
			Q.pop();
			map[current.first][current.second] = Riped;
			for (int j = 0; j < 4; j++)
			{
				temp = make_pair(current.first + dir[j][0], current.second + dir[j][1]);
				if (temp.first >= 0 && temp.second >= 0)
				{
					if (temp.first < g_Row && temp.second < g_Col)
					{
						if (map[temp.first][temp.second] == Normal && !visited[temp.first][temp.second])
						{
							Q.push(temp);
							visited[temp.first][temp.second] = true;
						}
					}
				}
			}
			
		}
		day++;
	}

	for (int i = 0; i < g_Row; i++)
	{
		for (int j = 0; j < g_Col; j++)
		{
			if (map[i][j] == Normal)
			{
				cout << -1;
				return 0;
			}
			
		}
	}
	cout << day;
	return 0;
}
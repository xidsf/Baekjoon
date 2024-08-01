#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char map[100][100];
char RGmap[100][100];
int mapSize;
pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void DFS(int x, int y, char c, char maps[][100])
{
	stack<pair<int, int>> s;
	s.push({ y, x });
	maps[y][x] = 'X';
	while (!s.empty())
	{
		pair<int, int> currentPos = s.top();
		pair<int, int> tempPos;
		s.pop();

		for (int i = 0; i < 4; i++)
		{
			tempPos = { currentPos.first + dir[i].first, currentPos.second + dir[i].second };

			if (tempPos.first >= mapSize || tempPos.second >= mapSize || tempPos.first < 0 || tempPos.second < 0)
			{
				continue;
			}

			if (maps[tempPos.first][tempPos.second] == c)
			{
				s.push(tempPos);
				maps[tempPos.first][tempPos.second] = 'X';
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> mapSize;
	int normal = 0;
	int RG = 0;
	string s;

	for (int i = 0; i < mapSize; i++)
	{
		cin >> s;
		for (int j = 0; j < mapSize; j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'G')
			{
				RGmap[i][j] = 'R';
			}
			else
			{
				RGmap[i][j] = s[j];
			}
		}
	}

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			if (map[i][j] != 'X')
			{
				DFS(j, i, map[i][j], map);
				normal++;
			}
		}
	}

	cout << normal << " ";

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			if (RGmap[i][j] != 'X')
			{
				DFS(j, i, RGmap[i][j], RGmap);
				RG++;
			}
		}
	}

	cout << RG;

	return 0;
}
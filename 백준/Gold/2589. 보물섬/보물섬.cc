#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool map[51][51];
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {-1 , 0}, {0, -1} };
int width, height;

int BFS(int fheight, int fwidth)
{
	bool unvisited[51][51];
	memcpy(unvisited, map, sizeof(bool) * 51 * 51);

	queue<pair<int, int>> q;
	q.push({ fheight, fwidth });
	int depth = -1;
	int QSize;
	while (!q.empty())
	{
		QSize = q.size();
		
		for (int k = 0; k < QSize; k++)
		{
			pair<int, int> currentPos = q.front();
			q.pop();
			unvisited[currentPos.first][currentPos.second] = false;
			pair<int, int> tempPos;

			for (int i = 0; i < 4; i++)
			{
				tempPos = { currentPos.first + dir[i].first, currentPos.second + dir[i].second };

				if (tempPos.first < 0 || tempPos.second < 0 || tempPos.first > height || tempPos.second > width)
				{
					continue;
				}

				if (unvisited[tempPos.first][tempPos.second] == true)
				{
					unvisited[tempPos.first][tempPos.second] = false;
					q.push(tempPos);
				}
			}
		}
		depth++;
	}
	return depth;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> height >> width;
	
	for (int i = 0; i < height; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < width; j++)
		{
			map[i][j] = input[j] == 'L' ? true : false;
		}
	}

	int maxDepth = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == true)
			{
				int bfsret = BFS(i, j);

				if (bfsret > maxDepth)
				{
					maxDepth = bfsret;
				}
			}
		}
	}

	cout << maxDepth;

	return 0;
}
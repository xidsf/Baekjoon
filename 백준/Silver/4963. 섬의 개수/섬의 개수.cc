#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int map[50][50];
int width, height;


void DFS(int x, int y)
{
	pair<int, int> dir[8] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1},{-1, -1}, {1, -1}, {-1, 1} };

	stack<pair<int, int>> s;
	s.push({ y, x });
	map[y][x] = 0;
	while (!s.empty())
	{
		pair<int, int> currentPos = s.top();
		pair<int, int> tempPos;
		s.pop();

		for (int i = 0; i < 8; i++)
		{
			tempPos = { currentPos.first + dir[i].first, currentPos.second + dir[i].second };

			if (tempPos.first >= height || tempPos.second >= width || tempPos.first < 0 || tempPos.second < 0)
				continue;

			if (map[tempPos.first][tempPos.second] == 1)
			{
				s.push(tempPos);
				map[tempPos.first][tempPos.second] = 0;
			}
		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> width >> height;
	while (width != 0 && height != 0)
	{
		memset(map, 0, 50 * 50 * sizeof(int));
		int ans = 0;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 1)
				{
					DFS(j, i);
					ans++;
				}
			}
		}

		cout << ans << "\n";

		cin >> width >> height;

	}
	
	return 0;
}
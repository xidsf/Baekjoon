#include <iostream>
#include <stack>
using namespace std;

bool map[51][51];
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {-1 , 0}, {0, -1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int width, height, cnt;
		int ans = 0;
		cin >> width >> height >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			int x, y;
			cin >> x >> y;

			map[x][y] = true;
		}

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (map[i][j] == true)
				{
					ans++;
					stack<pair<int, int>> s;
					pair<int, int> currentPos;
					s.push(make_pair(i, j));
					map[i][j] = false;
					while (!s.empty())
					{
						currentPos = s.top();
						for (int k = 0; k < 4; k++)
						{
							pair<int, int> tempPos = { currentPos.first + dir[k].first, currentPos.second + dir[k].second };

							if (tempPos.first < 0 || tempPos.second < 0)
							{
								continue;
							}

							if (map[tempPos.first][tempPos.second] == true)
							{
								s.push(make_pair(tempPos.first, tempPos.second));
								map[tempPos.first][tempPos.second] = false;
								break;
							}
						}
						if (currentPos == s.top())
						{
							s.pop();
						}
					}
				}
			}
		}

		cout << ans << "\n";
	}


	return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct p
{
	int row, col;
} Point;

Point moveDir[8] = { {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1} };
bool visited[301][301];

int main()
{
	int testCount;
	cin >> testCount;

	int length;
	Point start, end;
	Point current, temp;
	int tempX, tempY;
	int qSize, ans;
	queue<Point> q;
	for (int i = 0; i < testCount; i++)
	{
		memset(visited, 0, 301 * 301 * sizeof(bool));
		ans = -1;
		cin >> length;

		cin >> tempX >> tempY;
		start = { tempX, tempY };

		cin >> tempX >> tempY;
		end = { tempX, tempY };

		q.push(start);
		visited[start.row][start.col] = true;

		while (!q.empty())
		{
			qSize = q.size();
			ans++;
			for (int j = 0; j < qSize; j++)
			{
				current = q.front();
				q.pop();
				if (current.row == end.row && current.col == end.col)
				{
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				for (int i = 0; i < 8; i++)
				{
					temp.row = current.row + moveDir[i].row;
					temp.col = current.col + moveDir[i].col;

					if (temp.row >= 0 && temp.col >= 0 && temp.row < length && temp.col < length)
					{
						if (!visited[temp.row][temp.col])
						{
							visited[temp.row][temp.col] = true;
							q.push(temp);
						}
					}

				}
			}
		}
		cout << ans << "\n";
	}

	
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

Point around[4] = { {1, 0}, {0, 1}, {-1,0}, {0, -1} };

int map[101][101];
Point visited[10000];

int main()
{
	queue<Point> route;
	int visitedCnt = 1;
	int row, column;
	cin >> row >> column;
	string inputRow;
	int ans = 1;


	
	for (int i = 0; i < row; i++)
	{
		cin >> inputRow;
		for (int j = 0; j < column; j++)
		{
			if (inputRow[j] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	Point testPoint;
	Point currentPoint;
	bool isVisited;
	route.push({ 0, 0 });
	visited[0] = { 0, 0 };
	int qs;
	while (!route.empty())
	{
		qs = route.size();

		for (int k = 0; k < qs; k++)
		{
			currentPoint = route.front();
			route.pop();
			for (int i = 0; i < 4; i++)
			{
				isVisited = false;
				testPoint.x = currentPoint.x + around[i].x;
				testPoint.y = currentPoint.y + around[i].y;
				if (testPoint.x == column - 1 && testPoint.y == row - 1)
				{
					ans++;
					cout << ans;
					return 0;
				}
				if (testPoint.x >= 0 && testPoint.x < column && testPoint.y >= 0 && testPoint.y < row)
				{
					for (int j = 0; j < visitedCnt - 1; j++)
					{
						if (visited[j].x == testPoint.x && visited[j].y == testPoint.y)
						{
							isVisited = true;
							break;
						}
					}
					if (!isVisited && map[testPoint.y][testPoint.x] == 1)
					{
						route.push(testPoint);
						visited[visitedCnt++] = testPoint;
					}
				}
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}

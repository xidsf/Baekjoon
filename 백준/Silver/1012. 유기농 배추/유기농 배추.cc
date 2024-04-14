#include <iostream>
#include <stack>
using namespace std;

int map[50][50] = { 0, };

typedef struct point {
	int x;
	int y;
}Point;

Point arround[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool ArroundCheck(Point point, int row, int column)
{
	if (point.x > column - 1 || point.x < 0) return false;
	if (point.y > row - 1 || point.y < 0) return false;
	if(map[point.y][point.x] == 1)
	{
		map[point.y][point.x] = 0;
		return true;
	}
	return false;
}

void InitMap()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			map[i][j] = 0;
		}
	}
}

int main()
{
	int TestCase;
	cin >> TestCase;

	int row, column;
	int cnt;
	int posX, posY;

	stack<Point> s;
	Point currentPoint;
	Point tempPoint;
	int ans = 0;

	for (int i = 0; i < TestCase; i++)
	{
		InitMap();
		ans = 0;
		cin >> column >> row >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			cin >> posX >> posY;
			map[posY][posX] = 1;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (map[i][j] == 1)
				{
					ans++;
					currentPoint.x = j;
					currentPoint.y = i;
					s.push(currentPoint);
					map[i][j] = 0;
					while (!s.empty())
					{
						currentPoint = s.top();
						s.pop();
						for (int k = 0; k < 4; k++)
						{
							tempPoint.x = currentPoint.x + arround[k].x;
							tempPoint.y = currentPoint.y + arround[k].y;
							if (ArroundCheck(tempPoint, row, column))
							{
								s.push(tempPoint);
							}
						}
						
					}
				}
			}
		}
		cout << ans << "\n";
	}



	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

typedef struct monkeypoint {
	Point point;
	int left_Horse_Move;
}M_Point;

int map[200][200][31];

Point HorseMove[8] = { {2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1} };
Point MonkeyMove[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };



int main()
{
	int H_Move;
	cin >> H_Move;
	queue<monkeypoint> q;
	int row, column, t;
	cin >> column >> row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> t;
			for (int k = 0; k < 31; k++)
			{
				map[i][j][k] = t;
			}
		}
	}

	if (row == 1 && column == 1)
	{
		cout << 0;
		return 0;
	}

	q.push({ 0, 0, H_Move });
	map[0][0][H_Move] = -1;
	int qs, ans = 0;

	M_Point current_M_Point;
	M_Point temp_M_Point;
	current_M_Point.left_Horse_Move = H_Move;



	while (!q.empty())
	{
		qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			current_M_Point = q.front();
			q.pop();

			if (current_M_Point.left_Horse_Move > 0)
			{
				for (int j = 0; j < 8; j++)
				{
					temp_M_Point.point.x = current_M_Point.point.x + HorseMove[j].x;
					temp_M_Point.point.y = current_M_Point.point.y + HorseMove[j].y;
					temp_M_Point.left_Horse_Move = current_M_Point.left_Horse_Move - 1;

					if (temp_M_Point.point.x == column - 1 && temp_M_Point.point.y == row - 1)
					{
						ans++;
						cout << ans;
						return 0;
					}

					if (temp_M_Point.point.x >= 0 && temp_M_Point.point.x < column && temp_M_Point.point.y >= 0 && temp_M_Point.point.y < row)
					{
						if (map[temp_M_Point.point.y][temp_M_Point.point.x][temp_M_Point.left_Horse_Move] == 0)
						{
							q.push(temp_M_Point);
							map[temp_M_Point.point.y][temp_M_Point.point.x][temp_M_Point.left_Horse_Move] = -1;
						}
					}
				}
			}
			for (int j = 0; j < 4; j++)
			{
				temp_M_Point.point.x = current_M_Point.point.x + MonkeyMove[j].x;
				temp_M_Point.point.y = current_M_Point.point.y + MonkeyMove[j].y;
				temp_M_Point.left_Horse_Move = current_M_Point.left_Horse_Move;

				if (temp_M_Point.point.x == column - 1 && temp_M_Point.point.y == row - 1)
				{
					ans++;
					cout << ans;
					return 0;
				}

				if (temp_M_Point.point.x >= 0 && temp_M_Point.point.x < column && temp_M_Point.point.y >= 0 && temp_M_Point.point.y < row)
				{
					if (map[temp_M_Point.point.y][temp_M_Point.point.x][temp_M_Point.left_Horse_Move] == 0)
					{
						q.push(temp_M_Point);
						map[temp_M_Point.point.y][temp_M_Point.point.x][temp_M_Point.left_Horse_Move] = -1;
					}
				}
			}
		}
		ans++;
	}

	cout << -1;

	return 0;
}


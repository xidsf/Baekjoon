#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct p
{
	int x, y;
} Point;

int maxX, maxY, squareCount;
int map[100][100];
Point dir[4] = { {1,0}, {0,1}, {-1, 0}, {0, -1} };
stack<Point> s;

int DFS(int x, int y, int fsize)
{
	map[y][x] = 1;
	Point current, temp;
	int size = fsize;

	current = s.top();

	for (int i = 0; i < 4; i++)
	{
		temp.x = current.x + dir[i].x;
		temp.y = current.y + dir[i].y;

		if (temp.x < maxX && temp.y < maxY && temp.x >= 0 && temp.y >= 0 && map[temp.y][temp.x] == 0)
		{
			s.push(temp);
			map[temp.y][temp.x] = 1;
			size = DFS(temp.x, temp.y, size + 1);
		}
	}
	s.pop();

	return size;
}


int main()
{
	cin >> maxY >> maxX >> squareCount;
	vector<int> ans;
	int temp1X, temp1Y, temp2X, temp2Y;
	int count = 0;
	for (int i = 0; i < squareCount; i++)
	{
		cin >> temp1X >> temp1Y >> temp2X >> temp2Y;
		for (int k = temp1Y; k < temp2Y; k++)
		{
			for (int j = temp1X; j < temp2X; j++)
			{
				map[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < maxY; i++)
	{
		for (int j = 0; j < maxX; j++)
		{
			if (map[i][j] == 0)
			{
				count++;
				s.push({ j, i });
				ans.push_back(DFS(j, i, 1));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << count << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		
		cout << ans[i] << " ";
	}
	
	return 0;
}
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int map[100][100];
bool visited[100][100];
stack<pair<int, int>> s;
int maxArea = 1;
int length;
pair<int, int> dir[4] = { make_pair(1, 0), make_pair(0, 1) , make_pair(-1, 0) , make_pair(0, -1) };

void DFS(int x, int y, int height)
{
	s.push(make_pair(x, y));
	pair<int, int> current, temp;
	current = s.top();
	visited[current.second][current.first] = true;

	for (int i = 0; i < 4; i++)
	{
		temp.first = current.first + dir[i].first;
		temp.second = current.second + dir[i].second;

		if (temp.first < length && temp.second < length && temp.first >= 0 && temp.second >= 0)
		{
			if (map[temp.second][temp.first] > height && !visited[temp.second][temp.first])
			{
				visited[temp.second][temp.first] = true;
				DFS(temp.first, temp.second, height);
			}
		}
	}
	s.pop();
}

int main()
{
	int maxHeight = 0;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cin >> map[i][j];
			if(maxHeight < map[i][j]) maxHeight = map[i][j];
		}
	}
	int area;
	for (int k = 1; k < maxHeight; k++)
	{
		memset(visited, 0, 100 * 100 * sizeof(bool));
		area = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (map[i][j] > k && !visited[i][j])
				{
					area++;
					DFS(j, i, k);
				}
			}
		}
		if (maxArea < area) maxArea = area;
	}
	cout <<  maxArea;

	return 0;
}
#include <iostream>
#include <limits>
#include <cstring>
#include <queue>
using namespace std;

int mapSize;
int map[125][125];
int costMap[125][125];
bool visited[125][125];

pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

typedef struct node
{
	pair<int, int> pos;
	int cost;
}Node;

struct cmp
{
	bool operator()(Node n1, Node n2)
	{
		return n1.cost > n2.cost;
	}
};

void DIJ()
{
	while (true)
	{
		priority_queue<Node, vector<Node>, cmp> q;

		for (int i = 0; i < mapSize; i++)
		{
			for (int j = 0; j < mapSize; j++)
			{
				if (visited[i][j] == false && costMap[i][j] != numeric_limits<int>::max())
				{
					Node tempNode = { {i, j}, costMap[i][j] };
					q.push(tempNode);
				}
			}
		}

		if (q.empty()) break;

		Node minCostPos = q.top();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> tempPos = { minCostPos.pos.first + dir[i].first, minCostPos.pos.second + dir[i].second };

			if (tempPos.first < 0 || tempPos.second < 0 || tempPos.first > mapSize || tempPos.second > mapSize)
				continue;

			if (minCostPos.cost + map[tempPos.first][tempPos.second] < costMap[tempPos.first][tempPos.second])
			{
				costMap[tempPos.first][tempPos.second] = minCostPos.cost + map[tempPos.first][tempPos.second];
			}

		}
		visited[minCostPos.pos.first][minCostPos.pos.second] = true;
	}

}

int main()
{
	int cnt = 1;
	while (true)
	{
		cin >> mapSize;
		if (mapSize == 0) break;

		memset(visited, false, 125 * 125 * sizeof(bool));

		for (int i = 0; i < mapSize; i++)
		{
			for (int j = 0; j < mapSize; j++)
			{
				cin >> map[i][j];
				costMap[i][j] = numeric_limits<int>::max();
			}
		}

		costMap[0][0] = map[0][0];

		DIJ();

		cout << "Problem " << cnt << ": " << costMap[mapSize - 1][mapSize - 1] << "\n";
		cnt++;

	}

	return 0;
}
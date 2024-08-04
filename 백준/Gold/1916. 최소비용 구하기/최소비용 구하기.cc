#include <iostream>
#include <limits>
#include <cstring>
#include <queue>
using namespace std;

int cityCnt;
int busCnt;
int depart;
int arrive;
int arr[1001][1001];
int minCost[1001];
bool visited[1001] = { false, };

typedef struct node
{
	int pos;
	int cost;
}Node;

struct cmp
{
	bool operator()(Node n1, node n2)
	{
		return n1.cost > n2.cost;
	}
};

void Dij()
{
	for (int i = 0; i < cityCnt; i++)
	{
		priority_queue<Node, vector<Node>, cmp> posCost;

		for (int j = 1; j <= cityCnt; j++)
		{
			if (visited[j] == false)
			{
				Node tempNode = { j, minCost[j] };

				posCost.push(tempNode);
			}
		}

		Node current = posCost.top();
		visited[current.pos] = true;
		if (current.cost == INT32_MAX) continue;
		for (int i = 1; i <= cityCnt; i++)
		{
			if (current.pos == i) continue;
			if (arr[current.pos][i] >= 0)
			{
				if (minCost[i] > current.cost + arr[current.pos][i])
				{
					minCost[i] = current.cost + arr[current.pos][i];
				}
			}
		}
	}
}

int main()
{
	memset(arr, -1, 1001 * 1001 * sizeof(int));

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> cityCnt >> busCnt;

	for (int i = 0; i < busCnt; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (arr[start][end] < 0 || arr[start][end] > cost)
		{
			arr[start][end] = cost;
		}
	}

	cin >> depart >> arrive;

	minCost[depart] = 0;
	for (int i = 1; i <= cityCnt; i++)
	{
		if (i == depart) continue;
		minCost[i] = numeric_limits<int>::max();
	}

	Dij();

	cout << minCost[arrive];

	return 0;
}
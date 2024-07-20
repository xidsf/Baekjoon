#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

bool visisted[1001];
bool graph[1001][1001];
int node, edge;
int start;

void DFS()
{
	stack<int> s;
	s.push(start);
	visisted[start] = true;
	cout << start << " ";
	int currentnode;

	while (!s.empty())
	{
		currentnode = s.top();
		for (int i = 1; i <= node; i++)
		{
			if (graph[currentnode][i] == true && visisted[i] == false)
			{
				s.push(i);
				visisted[i] = true;
				cout << i << " ";
				break;
			}
		}

		if (currentnode == s.top())
		{
			s.pop();
		}
	}
}

void BFS()
{
	queue<int> q;
	q.push(start);
	visisted[start] = true;
	int currentnode;

	while (!q.empty())
	{
		currentnode = q.front();
		cout << currentnode << " ";
		q.pop();
		for (int i = 1; i <= node; i++)
		{
			if (graph[currentnode][i] == true)
			{
				if (visisted[i] == false)
				{
					q.push(i);
					visisted[i] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> node >> edge >> start;

	for (int i = 0; i < edge; i++)
	{
		int node1, node2;

		cin >> node1 >> node2;

		graph[node1][node2] = true;
		graph[node2][node1] = true;
	}

	memset(visisted, 0, 1001 * sizeof(bool));
	DFS();
	cout << "\n";
	memset(visisted, 0, 1001 * sizeof(bool));
	BFS();

	return 0;
}
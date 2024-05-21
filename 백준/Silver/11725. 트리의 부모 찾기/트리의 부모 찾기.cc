#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int parent[100001];

void dfs(int start)
{
	for (int i = 0; i < v[start].size(); i++)
	{
		if (!visited[v[start][i]])
		{
			parent[v[start][i]] = start;
			visited[v[start][i]] = true;
			dfs(v[start][i]);
		}
	}
}

int main()
{
	int cnt;
	cin >> cnt;

	int node1, node2;

	for (int i = 0; i < cnt - 1; i++)
	{
		cin >> node1 >> node2;

		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	dfs(1);

	for (int i = 2; i < cnt + 1; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}
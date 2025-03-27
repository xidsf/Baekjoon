#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> nodes[1001];

int main()
{
	int nodeCnt, searchingNodeCnt;
	cin >> nodeCnt >> searchingNodeCnt;

	for (int i = 0; i < nodeCnt - 1; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;

		nodes[node1].push_back({node2, weight});
		nodes[node2].push_back({node1, weight});
	}

	for (int i = 0; i < searchingNodeCnt; i++)
	{
		queue<pair<int, int>> q;
		int visited[1001] = {0, };
		int start, end;
		cin >> start >> end;
		q.push({ start , 0 });
		int ans = 0;
		bool isEnd = false;
		while (!q.empty())
		{
			pair<int, int> current = q.front();
			q.pop();
			visited[current.first] = current.second;

			for (int i = 0; i < nodes[current.first].size(); i++)
			{
				int target = nodes[current.first][i].first;
				if (target == end)
				{
					cout << nodes[current.first][i].second + current.second << "\n";
					isEnd = true;
					break;
				}
				if (visited[target] == 0)
				{
					visited[target] = nodes[current.first][i].second + current.second;
					q.push({ nodes[current.first][i].first, visited[target] });
				}
			}
			if (isEnd) break;
		}

	}

	return 0;
}
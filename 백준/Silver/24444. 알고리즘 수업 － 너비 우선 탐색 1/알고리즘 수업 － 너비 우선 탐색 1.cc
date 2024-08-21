#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int visited[100001] = { 0, };
vector<vector<int>> arr;


int main()
{
	int edge, vertex, start;

	cin >> vertex >> edge >> start;

	arr = vector<vector<int>>(vertex + 1);

	for (int i = 0; i < edge; i++)
	{
		int edge1, edge2;

		cin >> edge1 >> edge2;

		arr[edge1].push_back(edge2);
		arr[edge2].push_back(edge1);
	}

	for (int i = 1; i <= vertex; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	queue<int> q;

	q.push(start);
	visited[start] = 1;

	int currentPos;
	int currentCnt = 2;

	while (!q.empty())
	{
		currentPos = q.front();

		q.pop();
		
		for (int i = 0; i < arr[currentPos].size(); i++)
		{
			if (visited[arr[currentPos][i]] == 0)
			{
				q.push(arr[currentPos][i]);
				visited[arr[currentPos][i]] = currentCnt++;;
			}
		}

	}

	for (int i = 1; i <= vertex; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}
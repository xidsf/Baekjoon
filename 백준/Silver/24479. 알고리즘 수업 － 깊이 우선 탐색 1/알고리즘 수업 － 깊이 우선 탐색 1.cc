#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visited[100001] = { 0, };
vector<vector<int>> arr;

int initStart;
int currentCnt = 1;

void DFS(int start)
{
	visited[start] = currentCnt++;

	for (int i = 0; i < arr[start].size(); i++)
	{
		if (visited[arr[start][i]] == 0)
		{
			DFS(arr[start][i]);
		}
	}
}

int main()
{
	int edge, vertex;
	cin >> vertex >> edge >> initStart;

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

	DFS(initStart);

	for (int i = 1; i <= vertex; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}
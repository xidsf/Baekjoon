#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool visited[1000001];

int main()
{
	int depth = 0;
	int current = 0;
	int up, down, goal, start ,max;
	cin >> max >> start >> goal >> up >> down;
	int qSize;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			current = q.front();
			q.pop();
			if (current == goal)
			{
				cout << depth;
				return 0;
			}
			if (current + up <= max && !visited[current + up])
			{
				visited[current + up] = true;
				q.push(current + up);
			}
			if (current - down >= 1 && !visited[current - down])
			{
				visited[current - down] = true;
				q.push(current - down);
			}
		}
		depth++;
	}
	cout << "use the stairs";

	return 0;
}
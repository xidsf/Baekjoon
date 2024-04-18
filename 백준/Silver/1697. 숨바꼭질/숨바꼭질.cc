#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

bool CheckPoint(int point)
{
	if (point >= 0 && point <= 100000)
	{
		if (visited[point] == true) return false;
		visited[point] = true;
		return true;
	}
	else return false;
}

int main()
{
	queue<int> route;

	int currentPoint;
	int testPoint;
	int ansPoint;
	int ans = 0;

	int tempQueueSize;
	cin >> currentPoint >> ansPoint;

	route.push(currentPoint);

	while (!route.empty())
	{
		tempQueueSize = route.size();
		for (int i = 0; i < tempQueueSize; i++)
		{
			currentPoint = route.front();
			route.pop();
			if (currentPoint == ansPoint)
			{
				cout << ans;
				return 0;
			}

			testPoint = currentPoint + 1;
			if (CheckPoint(testPoint)) route.push(testPoint);

			testPoint = currentPoint - 1;
			if (CheckPoint(testPoint)) route.push(testPoint);

			testPoint = currentPoint * 2;
			if (CheckPoint(testPoint)) route.push(testPoint);
		}
		ans++;
	}

	return 0;
}

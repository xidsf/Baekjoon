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

	if (currentPoint == ansPoint)
	{
		cout << 0;
		return 0;
	}

	route.push(currentPoint);

	while (!route.empty())
	{
		tempQueueSize = route.size();
		for (int i = 0; i < tempQueueSize; i++)
		{
			currentPoint = route.front();
			route.pop();

			testPoint = currentPoint + 1;
			if (testPoint == ansPoint)
			{
				cout << ++ans;
				return 0;
			}
			if (CheckPoint(testPoint)) route.push(testPoint);

			testPoint = currentPoint - 1;
			if (testPoint == ansPoint)
			{
				cout << ++ans;
				return 0;
			}
			if (CheckPoint(testPoint)) route.push(testPoint);

			testPoint = currentPoint * 2;
			if (testPoint == ansPoint)
			{
				cout << ++ans;
				return 0;
			}
			if (CheckPoint(testPoint)) route.push(testPoint);
		}
		ans++;
	}

	cout << ans;

	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int visited[100001];

void Initarr()
{
	for (int i = 0; i < 100001; i++)
	{
		visited[i] = -1;
	}
}

bool CheckPoint(int point, int prev)
{
	if (point >= 0 && point <= 100000)
	{
		if (visited[point] >= 0) return false;
		visited[point] = prev;
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

	Initarr();
	while (!route.empty())
	{
		tempQueueSize = route.size();
		for (int i = 0; i < tempQueueSize; i++)
		{
			currentPoint = route.front();
			route.pop();
			if (currentPoint == ansPoint)
			{
				cout << "이동 횟수: " << ans << "\n";
				while (!route.empty()) route.pop();
				i = tempQueueSize;
				continue;
			}

			testPoint = currentPoint + 1;
			if (CheckPoint(testPoint, currentPoint)) route.push(testPoint);

			testPoint = currentPoint - 1;
			if (CheckPoint(testPoint, currentPoint)) route.push(testPoint);

			testPoint = currentPoint * 2;
			if (CheckPoint(testPoint, currentPoint)) route.push(testPoint);
		}
		ans++;
	}

	int* arr = new int[ans];
	int idx = ansPoint;
	for (int i = 0; i < ans + 1; i++)
	{
		arr[i] = idx;
		idx = visited[idx];
	}
	for (int i = ans; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum {
	None = 0, Home, Router
};

int main()
{
	vector<long long> co;
	int homeCnt, routerCnt;
	long long temp, max = 0;
	cin >> homeCnt >> routerCnt;

	for (int i = 0; i < homeCnt; i++)
	{
		cin >> temp;
		co.push_back(temp);
		if (max < temp) max = temp;
	}
	sort(co.begin(), co.end());
	
	int leftRouter;
	long long currentNode = 0;
	long long end = max - co[0];
	long long begin = 1, mid;

	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (begin == end) break;
		leftRouter = routerCnt - 1;
		currentNode = 0;
		for (int i = 1; i < homeCnt; i++)
		{
			if (co[i] - co[currentNode] >= mid)
			{
				leftRouter--;
				currentNode = i;
			}
		}
		if (leftRouter <= 0)
		{
			if (begin == mid)
			{
				mid++;
				leftRouter = routerCnt - 1;
				currentNode = 0;
				for (int i = 1; i < homeCnt; i++)
				{
					if (co[i] - co[currentNode] >= mid)
					{
						leftRouter--;
						currentNode = i;
					}
				}
				if (leftRouter > 0) mid--;
				break;
			}
			begin = mid;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << mid;

	return 0;
}
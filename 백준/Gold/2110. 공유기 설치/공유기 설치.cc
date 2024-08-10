#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int homeCount, routerCount;
	cin >> homeCount >> routerCount;

	vector<unsigned long long> map;
	for (int i = 0; i < homeCount; i++)
	{
		unsigned long long temp;
		cin >> temp;
		map.push_back(temp);
	}

	sort(map.begin(), map.end());

	unsigned long long start = 1;
	unsigned long long end = map.back();
	unsigned long long ans = 0;

	while (start <= end)
	{
		unsigned long long mid = (end - start) / 2 + start;

		unsigned long long currentPos = map[0];
		int currentRouterCount = routerCount - 1;

		for (int i = 1; i < homeCount; i++)
		{
			if (currentRouterCount <= 0) break;
			if (map[i] - currentPos >= mid)
			{
				currentRouterCount--;
				currentPos = map[i];
			}
		}

		if (currentRouterCount <= 0)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> region;
	int regioncnt, temp;
	long long totalBudget, maxbudget = 0;
	cin >> regioncnt;
	for (int i = 0; i < regioncnt; i++)
	{
		cin >> temp;
		region.push_back(temp);
		if (maxbudget < temp) maxbudget = temp;
	}
	cin >> totalBudget;
	


	long long min = 1, max = maxbudget, mid, leftBudget;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (min == max) break;
		leftBudget = totalBudget;
		for (int i = 0; i < regioncnt; i++)
		{
			if (region[i] > mid)
			{
				leftBudget -= mid;
			}
			else
			{
				leftBudget -= region[i];
			}
		}
		if (leftBudget < 0)
		{
			max = --mid;
		}
		else
		{
			if (min == mid)
			{
				mid++;
				leftBudget = totalBudget;
				for (int i = 0; i < regioncnt; i++)
				{
					if (region[i] > mid)
					{
						leftBudget -= mid;
					}
					else
					{
						leftBudget -= region[i];
					}
				}
				if (leftBudget < 0) mid--;
				break;
			}
			min = mid;
		}
	}
	cout << mid;
	return 0;
}
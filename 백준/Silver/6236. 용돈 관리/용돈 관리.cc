#include <iostream>
using namespace std;

int arr[100000];

int main()
{
	
	int day, cnt;

	cin >> day >> cnt;
	int mMax = 0;
	for (int i = 0; i < day; i++)
	{
		cin >> arr[i];
		mMax = max(mMax, arr[i]);
	}


	int start = mMax;
	int end = INT32_MAX;
	int ans = INT32_MAX;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		int currentMoney = 0;
		int M = 0;
		for (int i = 0; i < day; i++)
		{
			if (currentMoney < arr[i])
			{
				currentMoney = mid;
				currentMoney -= arr[i];
				M++;
			}
			else
			{
				currentMoney -= arr[i];
			}
		}

		if (M <= cnt)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
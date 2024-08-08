#include <iostream>
using namespace std;

int main()
{
	long long size;
	int k;
	cin >> size >> k;

	long long start = 1;
	long long end = size * size;
	
	long long ans = INT64_MAX;

	while (start <= end)
	{
		long long mid = (start + end) / 2;

		long long totalCnt = 0;

		for (int i = 1; i <= size; i++)
		{
			totalCnt += min(mid / i, size);
		}

		if (totalCnt < k)
		{
			start = mid + 1;
		}
		else if (totalCnt >= k)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
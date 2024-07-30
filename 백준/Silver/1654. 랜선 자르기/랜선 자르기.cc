#include <iostream>
using namespace std;

long long arr[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	cin >> K >> N;

	long long s = 1;
	long long e = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		if (e < arr[i])
		{
			e = arr[i];
		}
	}
	long long ans = -1;
	
	while (s <= e)
	{
		long long m = s + (e - s) / 2;
		long long cnt = 0;

		for (int i = 0; i < K; i++)
		{
			cnt += arr[i] / m;
		}

		if (cnt >= N)
		{
			ans = max(ans, m);
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}
	}

	cout << ans;

	return 0;
}
#include <iostream>
#define mod 1000000000
using namespace std;

unsigned long long nums[201][201] = { 0, };

unsigned long long DP(int num, int count)
{
	if (num < 0 || count < 0) return 0;

	if (nums[num][count] != 0)
	{
		return nums[num][count];
	}

	unsigned long long ret = 0;

	for (int i = 0; i <= num; i++)
	{
		ret += DP(num - i, count - 1);
		ret = ret % mod;
	}

	nums[num][count] = ret;

	return nums[num][count];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 201; i++)
	{
		nums[i][1] = 1;
		nums[i][2] = 1 + i;
	}

	int N, K;
	cin >> N >> K;

	cout << DP(N, K);

	return 0;
}
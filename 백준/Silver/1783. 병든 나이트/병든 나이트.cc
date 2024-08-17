#include <iostream>
using namespace std;

int main()
{
	long long N, M;
	cin >> N >> M;

	long long ans;
	
	if (N == 1)
	{
		ans = 1;
	}
	else if (N == 2)
	{
		ans = min((M + 1) / 2, (long long)4);
	}
	else
	{
		if (M < 7)
		{
			ans = min(M, (long long)4);
		}
		else
		{
			ans = M - 2;
		}
	}

	cout << ans;

	return 0;
}
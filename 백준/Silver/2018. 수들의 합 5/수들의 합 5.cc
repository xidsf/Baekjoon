#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;
	
	int maxCurrentNum = input / 2;
	int currentNum = 1;
	int k = 1;
	int sum = 0;
	int ans = 0;
	while (k != maxCurrentNum + 1)
	{
		for (int i = k; i <= maxCurrentNum + 1; i++)
		{
			sum += i;
			if (sum >= input)
			{
				if (sum == input)
				{
					ans++;
				}
				sum = 0;
				k++;
				break;
			}
		}
	}
	ans++;
	cout << ans;
	return 0;
}
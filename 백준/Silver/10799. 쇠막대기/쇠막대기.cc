#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int targetingBarCount = 0;
	int sum = 0;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				sum += targetingBarCount;
				i++;
			}
			else
			{
				targetingBarCount++;
				sum++;
			}
		}
		else if(s[i] == ')')
		{
			targetingBarCount--;
		}
	}

	cout << sum;

	return 0;
}
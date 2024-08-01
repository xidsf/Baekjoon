#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			s.pop();
		}
		else
		{
			s.push(input);
		}
	}

	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}
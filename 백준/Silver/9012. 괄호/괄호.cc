#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		stack<char> s;

		string input;
		cin >> input;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(')
			{
				s.push('(');
			}
			else
			{
				if (!s.empty() && s.top() == '(')
				{
					s.pop();
				}
				else
				{
					s.push(')');
					break;
				}
			}
		}
		if (s.empty())
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return 0;
}
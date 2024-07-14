#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node
{
	string str;

	bool operator > (const node copy) const
	{
		if (copy.str.length() < str.length())
		{
			return true;
		}
		else if (copy.str.length() > str.length())
		{
			return false;
		}

		int num1 = 0;
		int num2 = 0;
		int length = str.length();

		for (int i = 0; i < length; i++)
		{
			if ('0' <= str[i] && '9' >= str[i])
			{
				num1 += str[i] - '0';
			}
		}

		for (int i = 0; i < length; i++)
		{
			if ('0' <= copy.str[i] && '9' >= copy.str[i])
			{
				num2 += copy.str[i] - '0';
			}
		}

		if (num1 < num2)
		{
			return false;
		}
		else if(num1 > num2)
		{
			return true;
		}


		if (copy.str.compare(str) < 0)
		{
			return true;
		}
		return false;
	}
};




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;

	node s;
	priority_queue<node, vector<node>, greater<node>> q;

	for (int i = 0; i < cnt; i++)
	{
		cin >> s.str;

		q.push(s);

	}

	for (int i = 0; i < cnt; i++)
	{
		cout << q.top().str << "\n";
		q.pop();
	}

	return 0;
}
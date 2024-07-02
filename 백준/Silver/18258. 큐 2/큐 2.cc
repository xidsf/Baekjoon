#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;

	queue<int> q;
	string s;
	int input;
	for (int i = 0; i < cnt; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> input;
			q.push(input);
		}
		else if(s == "pop")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			cout << q.empty() ? 1 : 0;
			cout << "\n";
		}
		else if (s == "front")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (s == "back")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}


	return 0;
}
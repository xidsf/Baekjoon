#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<char> s;
	vector<string> v;

	int cnt;
	cin >> cnt;
	string temp;

	for (int i = 0; i < cnt; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	
	int ans = 0;
	bool loopCheck;
	for (int i = 0; i < cnt; i++)
	{
		loopCheck = true;
		for (int j = 0; j < v[i].size() ; j++)
		{
			if (!s.empty())
			{
				if (s.top() == v[i][j])
				{
					s.pop();
				}
				else
				{
					s.push(v[i][j]);
				}
			}
			else
			{
				s.push(v[i][j]);
			}
		}
		
		if (s.empty())
		{
			ans++;
		}
		while (!s.empty())
		{
			s.pop();
		}
	}

	cout << ans;

	return 0;
}
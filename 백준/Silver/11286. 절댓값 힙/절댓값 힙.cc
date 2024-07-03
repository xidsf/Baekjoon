#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;

	bool operator < (const node other) const
	{
		if (abs(data) < abs(other.data))
		{
			return false;
		}
		else if (abs(data) == abs(other.data))
		{
			if (data < other.data)
			{
				return false;
			}
			else return true;
		}
		else
		{
			return true;
		}
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<node> pq;

	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input;
		if (input != 0)
		{
			node n;
			n.data = input;
			pq.push(n);
		}
		else
		{
			if (pq.empty())
			{
				cout << 0 <<"\n";
				continue;
			}
			node n = pq.top();
			cout << n.data << "\n";
			pq.pop();
		}
	}


	return 0;
}
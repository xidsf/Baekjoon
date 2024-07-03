#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	

	int cnt;
	cin >> cnt;

	for (size_t i = 0; i < cnt * cnt; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
		if (pq.size() > cnt)
		{
			pq.pop();
		}
	}

	cout << pq.top();
	return 0;
}
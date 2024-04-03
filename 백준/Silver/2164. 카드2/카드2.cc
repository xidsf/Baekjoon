#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int cnt, temp;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		q.push(i + 1);
	}

	while (q.size() > 1)
	{
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();

	return 0;
}

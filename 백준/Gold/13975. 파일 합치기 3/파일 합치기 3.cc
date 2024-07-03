#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;

	

	for (int i = 0; i < testCase; i++)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		int fileCount;
		cin >> fileCount;
		for (int j = 0; j < fileCount; j++)
		{
			long long input;
			cin >> input;
			pq.push(input);
		}

		long long sum = 0;

		while (pq.size() > 1)
		{
			long long temp = pq.top();
			sum += pq.top();
			pq.pop();
			temp += pq.top();
			sum += pq.top();
			pq.pop();
			pq.push(temp);
		}
		cout << sum << "\n";
	}


	return 0;
}
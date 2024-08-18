#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct person
{
	int score1;
	int score2;
};

struct cmp1
{
	bool operator () (person p1, person p2)
	{
		if (p1.score1 < p2.score1)
		{
			return false;
		}
		else return true;
	}
};

person arr[100000];

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		priority_queue<person, vector<person>, cmp1> pq1;
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++)
		{
			int s1, s2;
			cin >> s1 >> s2;
			person temp = { s1, s2 };
			pq1.push(temp);
		}

		for (int j = 0; j < cnt; j++)
		{
			arr[j] = pq1.top();
			pq1.pop();
		}

		int tempMax = arr[0].score2;
		int ans = 1;

		for (int j = 1; j < cnt; j++)
		{
			if (arr[j].score2 < tempMax)
			{
				tempMax = arr[j].score2;
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
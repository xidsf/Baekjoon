#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> d;

void RotateDeque(int dir, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (dir == 1)
		{
			d.push_back(d.front());
			d.pop_front();
		}
		else if (dir == -1)
		{
			d.push_front(d.back());
			d.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt, numCnt;
	cin >> cnt >> numCnt;

	int input;

	for (int i = 1; i <= cnt; i++)
	{
		d.push_back(i);
	}

	vector<int> v;
	for (int i = 0; i < numCnt; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	int ans = 0;

	for (int i = 0; i < numCnt; i++)
	{
		int minLength = 51;
		int targetIndex;
		int minLengthDir;
		int minVectorIndex;
		for (int j = 0; j < d.size(); j++)
		{
			if (d[j] == v[i])
			{
				if (minLength >= j)
				{
					minLength = j;
					targetIndex = j;
					minLengthDir = 1;
					minVectorIndex = i;
				}
				if (minLength >= d.size() - j)
				{
					minLength = d.size() - j;
					targetIndex = j;
					minLengthDir = -1;
					minVectorIndex = i;
				}
			}
		}
		v[minVectorIndex] = 0;
		ans += minLength;
		RotateDeque(minLengthDir, minLength);
		d.pop_front();
	}

	cout << ans;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int day;
		cin >> day;

		vector<int> v;
		int highVal = 0;
		int highValIdx = 0;
		for (int j = 0; j < day; j++)
		{
			int temp;
			cin >> temp;

			v.push_back(temp);
		}

		int currentMax = v[day - 1];
		vector<int> highDays;
		highDays.push_back(day - 1);
		for (int j = day - 2; j >= 0; j--)
		{
			if (currentMax < v[j])
			{
				highDays.push_back(j);
				currentMax = v[j];
			}

		}

		int highDaysCnt = highDays.size() - 1;
		int startIdx = 0;
		int endIdx = highDays[highDaysCnt];
		long long benefit = 0;

		while (true)
		{
			for (int j = startIdx; j < endIdx; j++)
			{
				benefit += v[endIdx] - v[j];
			}
			startIdx = endIdx + 1;
			if (startIdx >= day) break;
			endIdx = highDays[--highDaysCnt];
		}
		cout << benefit << "\n";
	}

	return 0;
}
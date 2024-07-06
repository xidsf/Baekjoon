#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt, reqCount;
	cin >> cnt >> reqCount;

	long long min = 1;
	long long max = 0;

	vector<int> v;
	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
		if (max < input)
		{
			max = input;
		}
	}

	long long mid;
	int ans;

	while (min <= max)
	{
		int lineCont = 0;

		mid = min + (max - min) / 2;

		for (int i = 0; i < v.size(); i++)
		{
			lineCont += v[i] / mid;
		}

		if (lineCont >= reqCount)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
		

	}

	cout << --min;

	return 0;
}
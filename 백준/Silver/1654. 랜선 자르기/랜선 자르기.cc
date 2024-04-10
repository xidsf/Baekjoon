#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1;
	int cnt, input, line, max = 0;
	long long sum = 0;
	cin >> cnt >> line;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		v1.push_back(input);
		max = max < input ? input : max;
	}
	long long s = 1;
	long long e = max;
	long long m;

	while (s <= e)
	{
		sum = 0;
		m = s + (e - s) / 2;

		for (int i = 0; i < v1.size(); i++)
		{
			sum += v1[i] / m;
		}

		if (sum < line)
		{
			e = m - 1;
		}
		else if (sum >= line)
		{
			s = m + 1;
		}
	}
	cout << --s;
	
	return 0;
}
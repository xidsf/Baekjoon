#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int kid, cnt;
	long long temp, max = 0;
	long long sum = 0;
	cin >> kid >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		if (max < temp) max = temp;
	}
	
	if (sum < kid)
	{
		cout << 0;
		return 0;
	}


	long long start = 1;
	long long end = max;
	long long mid;
	
	int notGivenKid;
	while (start <= end)
	{
		notGivenKid = kid;
		mid = (start + end) / 2;
		if (start == end) break;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= mid)
			{
				notGivenKid -= v[i] / mid;
			}
		}
		if (notGivenKid <= 0)
		{
			if (mid == start)
			{
				notGivenKid = kid;
				mid++;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i] >= mid)
					{
						notGivenKid -= v[i] / mid;
					}
				}
				if (notGivenKid > 0)
				{
					mid--;
				}
				break;
			}
			start = mid;
		}
		else if (notGivenKid > 0)
		{
			end = mid - 1;
		}
		
	}
	cout << mid;
	return 0;
}
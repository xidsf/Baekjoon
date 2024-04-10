#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> wood;
	int woodcnt;
	long long needLen, max = 0, temp;
	cin >> woodcnt >> needLen;

	for (int i = 0; i < woodcnt; i++)
	{
		cin >> temp;
		wood.push_back(temp);
		if (max < temp) max = temp;
	}

	long long sum, begin = 0, end = max - 1, mid;

	while (begin <= end)
	{
		sum = 0;
		mid = (begin + end) / 2;
		if (begin == end) break;
		for (int i = 0; i < wood.size(); i++)
		{
			sum += ((wood[i] - mid) > 0 ? wood[i] - mid : 0);
		}
		
		if (sum >= needLen)
		{
			if (begin == mid)
			{
				mid++;
				sum = 0;
				for (int i = 0; i < wood.size(); i++)
				{
					sum += ((wood[i] - mid) > 0 ? wood[i] - mid : 0);
				}
				if (sum < needLen)
				{
					mid--;
				}
				break;
			}
			begin = mid;
		}
		else
		{
			mid--;
			end = mid;
		}

	}
	cout << mid;
	return 0;
}
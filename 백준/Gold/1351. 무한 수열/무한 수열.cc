#include <iostream>
#include <unordered_map>
using namespace std;

long long P, Q;

unordered_map<long long, long long> mem;

long long GetNum(long long index)
{
	if (index > 0)
	{
		long long left;
		long long right;

		auto findP = mem.find(index / P);
		
		if (findP == mem.end())
		{
			left = GetNum(index / P);
			mem.insert(make_pair(index / P, left));
		}
		else
		{
			left = findP->second;
		}

		auto findQ = mem.find(index / Q);

		if (findQ == mem.end())
		{
			right = GetNum(index / Q);
			mem.insert(make_pair(index / Q, right));
		}
		else
		{
			right = findQ->second;
		}
		
		return left + right;
	}
	else if(index == 0)
	{
		return 1;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long Num;

	cin >> Num >> P >> Q;

	long long ans = GetNum(Num);

	cout << ans;

	return 0;
}
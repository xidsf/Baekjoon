#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> outputv;
	int cnt, temp = 0, max = 1;


	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> temp;
		v1.push_back(temp);
		v2.push_back(temp);
		if (max < temp) max = temp;
	}

	sort(v1.begin(), v1.end());
	
	for (int i = 0; i < v1.size();)
	{
		outputv.push_back(v1[i]);
		cnt = upper_bound(v1.begin(), v1.end(), v1[i]) - lower_bound(v1.begin(), v1.end(), v1[i]);
		i += cnt;
	}


	for (int i = 0; i < v2.size(); i++)
	{
		cout << lower_bound(outputv.begin(), outputv.end(), v2[i]) - outputv.begin() << " ";
	}

	return 0;
}
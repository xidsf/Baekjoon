#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;
	int input, temp;


	cin >> input;
	for (int i = 0; i < input; i++)
	{
		cin >> temp;
		v1.push_back(temp);
	}
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		cin >> temp;
		v2.push_back(temp);
	}
	
	sort(v1.begin(), v1.end());

	for (int i = 0; i < v2.size(); i++)
	{
		temp = binary_search(v1.begin(), v1.end(), v2[i]) == true ? 1 : 0;
		cout << temp << "\n";
	}

	return 0;
}
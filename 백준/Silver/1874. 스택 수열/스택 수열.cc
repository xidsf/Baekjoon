#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main()
{
	stack<int> stack;
	int cnt, temp = 0;
	cin >> cnt;
	int* arr = new int[cnt];
	vector<char> v;
	int inputCount = 1;
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
	while (temp < cnt)
	{
		if (stack.empty() ||arr[temp] > stack.top())
		{
			stack.push(inputCount++);
			v.push_back('+');
		}
		else if (arr[temp] == stack.top())
		{
			stack.pop();
			v.push_back('-');
			temp++;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	vector<char>::iterator itor = v.begin();
	for (; itor != v.end(); itor++)
	{
		cout << *itor << "\n";
	}

	return 0;
}

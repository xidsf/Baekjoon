#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack<int> stack;
	int cnt, input, sum = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		if (input == 0 && !stack.empty()) stack.pop();
		else stack.push(input);
	}
	cnt = stack.size();
	for (int i = 0; i < cnt; i++)
	{
		sum += stack.top();
		stack.pop();
	}
	cout << sum;
	return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> stack;
	string s;
	bool isCorrect;
	
	while (true)
	{
		isCorrect = true;
		while (stack.size() > 0)
		{
			stack.pop();
		}
		getline(cin, s);
		if (s == ".") break;
		for (int i = 0; i < s.length(); i++)
		{
			if (!isCorrect) break;
			switch (s[i])
			{
			case '[':
				stack.push(']');
				break;
			case '(':
				stack.push(')');
				break;
			case ']':
				if (stack.size() > 0 && stack.top() == ']') stack.pop();
				else isCorrect = false;
				break;
			case ')':
				if (stack.size() > 0 && stack.top() == ')') stack.pop();
				else isCorrect = false;
				break;
			default:
				break;

			}
		}
		if (isCorrect && stack.size() == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> s;
		bool isNormal = true;

		for (int i = 0; i < str.length() ; i++)
		{
			if (isNormal == false) break;
			switch (str[i])
			{
				case '(':
					s.push('(');
					break;
				case ')':
					if (!s.empty() && s.top() == '(')
					{
						s.pop();
					}
					else
					{
						isNormal = false;
					}
					break;
				case '[':
					s.push('[');
					break;
				case ']':
					if (!s.empty() && s.top() == '[')
					{
						s.pop();
					}
					else
					{
						isNormal = false;
					}
					break;
			}

		}
		if(s.empty() && isNormal == true)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		
	}

	return 0;
}
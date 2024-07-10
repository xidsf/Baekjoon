#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unordered_set<string> s;

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		for (int j = 1; j <= input.length() - i; j++)
		{
			string temp;

			temp = input.substr(i, j);
			s.insert(temp);
		}
	}

	cout << s.size();

	return 0;
}
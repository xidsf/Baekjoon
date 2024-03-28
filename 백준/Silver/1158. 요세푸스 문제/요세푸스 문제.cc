#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> li;
	int person, term;
	cin >> person >> term;
	for (int i = 1; i <= person; i++)
	{
		li.push_back(i);
	}
	list<int>::iterator cur = li.begin();
	cout << "<";
	while (li.size() != 0)
	{
		for (int i = 0; i < term - 1; i++)
		{
			cur++;
			if (cur == li.end()) cur = li.begin();
		}
		cout << *cur;
		cur = li.erase(cur);
		if (cur == li.end()) cur = li.begin();
		if (li.size() != 0) cout << ", ";
	}
	cout << ">";

	return 0;
}

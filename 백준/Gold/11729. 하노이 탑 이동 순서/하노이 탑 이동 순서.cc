#include <iostream>
using namespace std;


void Move(int cnt, int start, int sub, int target)
{
	if (cnt == 1)
	{
		cout << start << " " << target << "\n";
	}
	if (cnt > 1)
	{
		Move(cnt - 1, start, target, sub);
		cout << start << " " << target << "\n";
		Move(cnt - 1, sub, start, target);
	}
	
}


int main()
{
	int input;
	cin >> input;
	int cnt = 1;
	for (int i = 0; i < input; i++)
	{
		cnt *= 2;
	}
	cnt--;
	cout << cnt << "\n";
	Move(input, 1, 2, 3);


	return 0;
}
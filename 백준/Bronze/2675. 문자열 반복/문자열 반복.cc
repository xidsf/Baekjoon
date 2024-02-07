#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LENGTH = 21;


int main()
{
	char* ch;
	ch = new char[MAX_LENGTH];
	
	int cnt_t, cnt;
	cin >> cnt_t;
	for (int i = 0; i < cnt_t; i++)
	{
		cin >> cnt >>ch;
		for (int j = 0; j < strlen(ch); j++)
		{
			for (int k = 0; k < cnt; k++) cout << ch[j];
		}
		cout << endl;
	}
	
	
	delete[]ch;
	return 0;
}
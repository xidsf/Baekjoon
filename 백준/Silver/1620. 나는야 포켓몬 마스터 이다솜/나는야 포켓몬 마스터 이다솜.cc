#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string str[100000];
unordered_map<string, int> numMap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int mapCount, QuestNum;

	cin >> mapCount >> QuestNum;

	for (int i = 0; i < mapCount; i++)
	{
		string input;
		cin >> input;

		str[i] = input;
		numMap.insert(make_pair(input, i + 1));
	}

	for (int i = 0; i < QuestNum; i++)
	{
		string input;
		cin >> input;

		if ('0' <= input[0] && input[0] <= '9')
		{
			int num = stoi(input);
			cout << str[num - 1] << "\n";
		}
		else
		{
			auto num = numMap.find(input);
			cout << num->second << "\n";
		}
	}

	return 0;
}
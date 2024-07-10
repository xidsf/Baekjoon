#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int ConvertStringTimeToInt(string s)
{
	string temp;
	temp = s[0];
	int hour = (s[0] - '0') * 10 + s[1] - '0';
	int minute = (s[3] - '0') * 10 + s[4] - '0';
	int time = hour * 60 + minute;
	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unordered_set<string> beforeStart;
	unordered_set<string> afterStart;

	string startEvent, endEvent, endingStreaming;

	cin >> startEvent >> endEvent >> endingStreaming;

	int start, end, endStreaming;
	start = ConvertStringTimeToInt(startEvent);
	end = ConvertStringTimeToInt(endEvent);
	endStreaming = ConvertStringTimeToInt(endingStreaming);

	while (!cin.eof())
	{
		string timeInput, nameInput;
		cin >> timeInput >> nameInput;
		if (timeInput == "-1") break;
		int time = ConvertStringTimeToInt(timeInput);

		if (time <= start)
		{
			beforeStart.insert(nameInput);
		}
		else if (time >= end && time <= endStreaming)
		{
			auto it = beforeStart.find(nameInput);
			if (it != beforeStart.end())
			{
				afterStart.insert(nameInput);
			}
		}
		
	}

	cout << afterStart.size();

	return 0;
}
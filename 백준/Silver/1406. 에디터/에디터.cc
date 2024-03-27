#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<char> List;
    string input;
    bool isEnd = false;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        List.push_back(input[i]);
    }
    int cnt;
    cin >> cnt;
    list<char>::iterator cur = List.end();
    cin.ignore();
    for (int i = 0; i < cnt; i++)
    {
        getline(cin, input);
        switch (input[0])
        {
            case 'L':
                if (cur == List.begin()) continue;
                else cur--;
                if (cur != List.end()) isEnd = false;
                break;
            case 'D':
                if (cur == List.end()) isEnd = true;
                else cur++;
                break;
            case 'B':
                if (cur == List.begin()) continue;
                else
                {
                    cur--;
                    cur = List.erase(cur);
                }
                break;
            case 'P':
                if (isEnd)
                {
                    List.push_back(input[2]);
                    cur = List.end();
                }
                else List.insert(cur, input[2]);
                break;
        }
    }
    for (cur = List.begin(); cur != List.end(); cur++)
    {
        cout << *cur;
    }

    return 0;
}
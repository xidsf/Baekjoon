#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> List = {};
    string input;
    bool isEnd = false;
    int cnt;
    cin >> cnt;
    list<char>::iterator cur = List.end();
    
    for (int i = 0; i < cnt; i++)
    {
        cin >> input;
        List.clear();
        for (int i = 0; i < input.length(); i++)
        {
            switch (input[i])
            {
            case '<':
                if (cur == List.begin()) continue;
                else cur--;
                if (cur != List.end()) isEnd = false;
                break;
            case '>':
                if (cur == List.end()) isEnd = true;
                else cur++;
                break;
            case '-':
                if (cur == List.begin()) continue;
                else
                {
                    cur--;
                    cur = List.erase(cur);
                }
                break;
            default:
                if (isEnd)
                {
                    List.push_back(input[i]);
                    cur = List.end();
                }
                else List.insert(cur, input[i]);
                break;
            }
        }
        for (cur = List.begin(); cur != List.end(); cur++)
        {
            cout << *cur;
        }
        cout << "\n";
    }

    return 0;
}
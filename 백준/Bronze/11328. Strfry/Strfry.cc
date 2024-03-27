#include <iostream>
using namespace std;

int main()
{
    string a, b;
    int arra[26];
    int arrb[26];
    bool isPossible;
    int cnt;
    cin >> cnt;

    for (int j = 0; j < cnt; j++)
    {
        cin >> a >> b;
        isPossible = true;
        for (int i = 0; i < 26; i++)
        {
            arra[i] = 0;
            arrb[i] = 0;
        }

        if (a.length() == b.length())
        {
            for (int i = 0; i < a.length(); i++)
            {
                arra[(int)a[i] - (int)'a']++;
                arrb[(int)b[i] - (int)'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (arra[i] != arrb[i])
                {
                    isPossible = false;
                    break;
                }
            }
        }
        else
        {
            isPossible = false;
        }

        if (isPossible)
        {
            cout << "Possible" << "\n";
        }
        else
        {
            cout << "Impossible" << "\n";
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int m, d, total;
    cin >> m >> d;
    total = 0;

    for (int i = 1; i < m; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            total += 31;
        }
        else if (i == 2)
        {
            total += 28;
        }
        else
        {
            total += 30;
        }
    }
    total += d - 1;
    total = total % 7;
    switch (total)
    {
        case 0:
            cout << "MON";
            break;
        case 1:
            cout << "TUE";
            break;
        case 2:
            cout << "WED";
            break;
        case 3:
            cout << "THU";
            break;
        case 4:
            cout << "FRI";
            break;
        case 5:
            cout << "SAT";
            break;
        case 6:
            cout << "SUN";
            break;
    }

    return 0;
}
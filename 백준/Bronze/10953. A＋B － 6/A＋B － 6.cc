#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cout << (int)(temp[0] - '0') + (int)(temp[2] - '0') << endl;
    }

    return 0;

}
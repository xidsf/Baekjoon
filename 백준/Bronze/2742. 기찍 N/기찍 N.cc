#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int input;
    cin >> input;

    for (int i = input; i > 0; i--)
    {
        cout << i << "\n";
    }

    return 0;
}
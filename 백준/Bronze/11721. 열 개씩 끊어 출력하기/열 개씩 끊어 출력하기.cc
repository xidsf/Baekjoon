#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int i;
    cout << input[0];
    for (i = 1; i < input.length(); i++)
    {
        if (i % 10 == 0) cout << endl;
        cout << input[i];
    }
    
    return 0;
}
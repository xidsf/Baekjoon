#include <iostream>
using namespace std;

int main()
{
    string a, b;
    int arr[26];
    int cnt = 0;
    cin >> a >> b;
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < a.length(); i++)
    {
        arr[(int)a[i] - (int)'a']++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        arr[(int)b[i] - (int)'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        cnt += (arr[i] < 0 ? -arr[i] : arr[i]);
    }
    cout << cnt;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arrint[3][2];
    int cnt, fibo, rep;

    cin >> cnt;

    for (int t = 0; t < cnt; t++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arrint[i][j] = 0;
            }
        }
        cin >> fibo;
        if (fibo == 1) rep = 1;
        else rep = 0;
        for (; rep <= fibo; rep++)
        {
            if (rep == 0)
            {
                arrint[0][0] = 1;
                arrint[0][1] = 0;
                arrint[2][0] = arrint[0][0] + arrint[1][0];
                arrint[2][1] = arrint[0][1] + arrint[1][1];
            }
            else if (rep == 1)
            {
                arrint[1][0] = 0;
                arrint[1][1] = 1;
                arrint[2][0] = arrint[0][0] + arrint[1][0];
                arrint[2][1] = arrint[0][1] + arrint[1][1];
            }
            else
            {
                arrint[2][0] = arrint[0][0] + arrint[1][0];
                arrint[2][1] = arrint[0][1] + arrint[1][1];
                arrint[0][0] = arrint[1][0];
                arrint[0][1] = arrint[1][1];
                arrint[1][0] = arrint[2][0];
                arrint[1][1] = arrint[2][1];
            }
        }
        cout << arrint[2][0] << " " << arrint[2][1] << endl;

    }

	return 0;
}
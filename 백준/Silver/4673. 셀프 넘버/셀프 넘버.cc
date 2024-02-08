#include <iostream>
using namespace std;
int SIZE = 10000;

int main()
{
    int N = 1;
    int temp = 0;
    bool* arr;
    arr = new bool[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = false;
    }
    
    for ( ;N <= SIZE; N++)
    {
        temp += N;
        for (int i = 1; i <= SIZE; i = i * 10)
        {
            if (N / i >= 1)
            {
                temp +=  (N % (i * 10)) / i;
                continue;
            }
        }
        if (temp <= SIZE)
        {
            arr[temp - 1] = true;
        }
        temp = 0;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == false)
        {
            cout << i + 1 << endl;
        }
    }
    delete[]arr;
	return 0;
}
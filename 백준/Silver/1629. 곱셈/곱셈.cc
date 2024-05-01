#include <iostream>
using namespace std;

int a, b, c;

long long int f(long long int y) {
	if (y == 1) return a % c;

	long long int k = f(y / 2) % c;

	if (y % 2 == 0) return k * k % c;
	else return k * k % c * a % c;
}

int main()
{
	cin >> a >> b >> c;
	
	long long ans = f(b);
	cout << ans;
	

	

	return 0;
}



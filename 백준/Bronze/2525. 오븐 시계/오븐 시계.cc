#include <iostream>
using namespace std;

int main()
{
	int h, m, cnt;
	cin >> h >> m;
	cin >> cnt;

	int h_cnt = cnt / 60;
	int m_cnt = cnt % 60;
	m = m + m_cnt;
	if (m >= 60)
	{
		h++;
		m = m % 60;
	}
	h = h + h_cnt;
	if (h >= 24)
	{
		h = h % 24;
	}
	cout << h << " " << m;
	return 0;
}
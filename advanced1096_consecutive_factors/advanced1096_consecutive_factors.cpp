#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int n_bak = n;
	int dbegin = n, dend = n+1;
	int begin = 2, end = 2;
	while (end<=n_bak)
	{
		if (n%end == 0)
		{
			n = n / end;
			end++;
		}
		else
		{
			if (end - begin > dend - dbegin)
			{
				dbegin = begin;
				dend = end;
			}
			else if (end - begin == dend - dbegin)
			{
				if (end < dend)
				{
					dbegin = begin;
					dend = end;
				}
			}
			begin = begin + 1;
			end = begin;
			n = n_bak;
		}
	}
	cout << dend - dbegin << endl;
	for (int i = dbegin; i < dend; i++)
	{
		cout << i;
		if (i != dend - 1)
			cout << '*';
	}
	return 0;
}
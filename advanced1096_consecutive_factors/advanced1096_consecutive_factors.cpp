#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin >> n;
	LL n_bak = n;
	LL dbegin = n, dend = n+1;
	LL begin = 2, end = 2;
	while ((end-2)*(end-2)<=n_bak)// end-2 important, for 6=2*3, expand the end condition
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
	for (LL i = dbegin; i < dend; i++)
	{
		cout << i;
		if (i != dend - 1)
			cout << '*';
	}
	return 0;
}
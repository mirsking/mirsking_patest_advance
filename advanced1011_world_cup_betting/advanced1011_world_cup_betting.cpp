#include <iostream>
using namespace std;

inline int max_odd(float *a)
{
	int res = 0;
	if (a[0] > a[1])
	{
		if (a[0] > a[2])
			res = 0;
		else
			res = 2;
	}
	else
	{
		if (a[1] > a[2])
			res = 1;
		else
			res = 2;
	}
	return res;
}

char wtl[] = {'W', 'T', 'L'};

int main()
{
	float a[3], b[3], c[3];

	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	cin >> c[0] >> c[1] >> c[2];

	int aa = max_odd(a);
	int bb = max_odd(b);
	int cc = max_odd(c);

	printf("%c %c %c %.2f", wtl[aa], wtl[bb], wtl[cc], (a[aa]*b[bb]*c[cc]*0.65-1)*2);
	
	return 0;
}
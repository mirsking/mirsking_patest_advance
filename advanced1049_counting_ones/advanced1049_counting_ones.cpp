#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long LL;

LL numOfOne(LL num)
{
	LL sum = 0;
	LL higher, lower, cur;
	int factor = 1;
	while (num / factor != 0)
	{
		higher = num / (factor*10);
		lower = num - (num / factor)*factor;
		cur = (num / factor) % 10;
		switch (cur)
		{
		case 0: sum += higher*factor;
			break;
		case 1: sum += higher*factor + lower + 1;
			break;
		default: sum += higher*factor + factor;
			break;
		}
		factor *= 10;
	}
	return sum;
}

int main()
{
	LL num;
	cin >> num;
	cout << numOfOne(num);
	return 0;
}
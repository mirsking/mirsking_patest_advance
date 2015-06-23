#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
	if (a == 1)
		return false;
	else if (a == 2)
		return true;

	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}

int reverseNum(int a, int radix)
{
	int res=0;
	while (a != 0)
	{
		res = res*radix + a%radix;
		a = a / radix;
	}
	return res;
}

int main()
{
	int m, radix;
	do{
		cin >> m >> radix;
		if (m <= 0)
			break;

		if (isPrime(m) && isPrime(reverseNum(m, radix)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;


	}while(m>0);

	return 0;
}
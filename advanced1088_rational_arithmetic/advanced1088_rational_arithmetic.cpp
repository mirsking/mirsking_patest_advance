#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
typedef long long LL;


LL gcd(LL a, LL b)
{
	if (a < b)
		swap(a, b);

	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void printNum(LL a, LL b)
{
	if (a == 0)
		printf("%lld", 0);
	else
	{
		bool negative = false;
		if (a < 0)
			negative = true;
		a = abs(a);
		LL c = a / b;
		a = a%b;

		if (negative)
			printf("(-");
		
		if (c != 0)
		{
			printf("%lld", c);
			if (a != 0)
				printf(" ");
		}
		if (a != 0)
			printf("%lld", a);
		if (b!=1)
			printf("/%lld", b);

		if (negative)
			printf(")");
	}
}

void simplify(LL& a, LL& b)
{
	bool negative = false;
	if ((a < 0&& b>0) || (a>0&&b<0))
		negative = true;

	a = abs(a);
	b = abs(b);
	LL c = gcd(a, b);
	a = a / c;
	b = b / c;
	if (negative)
		a = -a;
}

int main()
{
	LL a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

	simplify(a, b);
	simplify(c, d);

	// add
	LL tmpa, tmpb;
	tmpa = a*d + b*c;
	tmpb = b*d;
	simplify(tmpa, tmpb);
	printNum(a, b);
	printf(" + ");
	printNum(c, d);
	printf(" = ");
	printNum(tmpa, tmpb);
	printf("\n");
	
	// minius
	tmpa = a*d - b*c;
	tmpb = b*d;
	simplify(tmpa, tmpb);
	printNum(a, b);
	printf(" - ");
	printNum(c, d);
	printf(" = ");
	printNum(tmpa, tmpb);
	printf("\n");

	// multi
	tmpa = a*c;
	tmpb = b*d;
	simplify(tmpa, tmpb);
	printNum(a, b);
	printf(" * ");
	printNum(c, d);
	printf(" = ");
	printNum(tmpa, tmpb);
	printf("\n");
	
	// divide
	tmpa = a*d;
	tmpb = b*c;

	printNum(a, b);
	printf(" / ");
	printNum(c, d);
	printf(" = ");
	if (tmpb != 0)
	{
		simplify(tmpa, tmpb);
		printNum(tmpa, tmpb);
	}
	else
	{
		printf("Inf");
	}
	printf("\n");
	return 0;
}
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
/*求两个数的最大公约数：欧几里得算法*/
LL gcd(LL a, LL b)
{
	if (a < b)
		swap(a, b);

	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

/*求两个数的最小公倍数*/
LL lcm(LL a, LL b)
{
	return a*b / gcd(a, b);
}

/*求多个数的最小公倍数*/
LL nlcm(const vector<LL>& nums, LL n)
{
	if (n == 0)
		return -1;
	else if (n == 1)
		return nums[0];

	return lcm(nums[n - 1], nlcm(nums, n - 1));
}



struct RatNum{
	LL a;
	LL b;
	RatNum():a(0),b(0){}
};

int main()
{
	LL N;
	scanf("%lld\n", &N);
	RatNum res;
	res.a = 0; res.b = 1;
	for (LL i = 0; i < N; i++)
	{
		RatNum tmp;
		scanf("%lld/%lld", &(tmp.a), &(tmp.b));
		res.a = res.a*tmp.b + res.b*tmp.a;
		res.b = res.b*tmp.b;
		LL gg = gcd(labs(res.a), labs(res.b));
		res.a /= gg;
		res.b /= gg;
	}

	
	if (res.a == 0)
	{
		cout << "0";
		return 0;
	}
	if (res.b == 1)
		cout << res.a;
	else
	{
		if (res.a < res.b)
			cout << res.a << "/" << res.b;
		else
			cout << res.a / res.b << " " << res.a%res.b << "/" << res.b;
	}
		

	return 0;
}
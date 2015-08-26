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
	vector<RatNum> nums;
	vector<LL> bs;
	nums.resize(N);
	bs.resize(N);
	for (LL i = 0; i < N; i++)
	{
		scanf("%lld/%lld", &(nums[i].a), &(nums[i].b));
		bs[i] = nums[i].b;
	}

	LL ll = nlcm(bs, bs.size());
	//LL ll = *max_element(bs.begin(), bs.end());
	RatNum res;
	res.b = ll;
	res.a = 0;
	for (auto& num : nums)
	{
		res.a = res.a + num.a*ll / num.b;
	}
	LL gg = gcd(res.a, res.b);
	res.a = res.a / gg;
	res.b = res.b / gg;
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
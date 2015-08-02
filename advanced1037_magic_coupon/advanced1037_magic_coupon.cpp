#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define isPos(x) (x>0)
#define isNeg(x) (x<0)
typedef long long LL;
int main()
{
	int M, N;
	vector<LL> coupons, products;
	cin >> M;
	while (M--)
	{
		LL tmp;
		cin >> tmp;
		coupons.push_back(tmp);
	}
	sort(coupons.begin(), coupons.end());
	cin >> N;
	while (N--)
	{
		LL tmp;
		cin >> tmp;
		products.push_back(tmp);
	}
	sort(products.begin(), products.end());

	LL sum = 0;
	for (auto it1 = coupons.rbegin(), it2 = products.rbegin();
		it1 != coupons.rend(), it2!= products.rend();)
	{
		if (isPos(*it1) && isPos(*it2))
		{
			sum += *it1 * *it2;
			it1++; it2++;
		}
		else
			break;
	}
	for (auto it1 = coupons.begin(), it2 = products.begin();
		it1 != coupons.end(), it2!= products.end();)
	{
		if (isNeg(*it1) && isNeg(*it2))
		{
			sum += *it1 * *it2;
			it1++; it2++;
		}
		else
			break;
	}
	cout << sum;
	return 0;
}
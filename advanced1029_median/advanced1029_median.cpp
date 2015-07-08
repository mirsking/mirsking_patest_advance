#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<long long> a, b;
	int n;
	scanf("%lld", &n);
	while (n--)
	{
		long long tmp;
		scanf("%lld", &tmp);
		a.push_back(tmp);
	}
	scanf("%lld", &n);
	while (n--)
	{
		int tmp;
		scanf("%lld", &tmp);
		b.push_back(tmp);
	}
	
	/*
	int ma = a[(a.size() - 1) / 2];
	int mb = b[(b.size() - 1) / 2];
	vector<int> c;
	if (ma <= mb)
	{
		int i = (a.size() - 1) / 2;
		while (i < a.size() && a[i] <= mb)
		{
			c.push_back(a[i]);
			i++;
		}
		c.push_back(mb);
	}
	else 
	{
		int i = (b.size()-1)/2;
		while (i < b.size() && b[i] <= ma)
		{
			c.push_back(b[i]);
			i++;
		}
		c.push_back(ma);
	}
	*/
	vector<long long> c;
	c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	cout << c[(c.size() - 1) / 2];

	return 0;
}
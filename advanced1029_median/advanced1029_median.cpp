#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> a, b;
	int n;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	vector<int> c;
	c.resize(a.size() + b.size());

	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	cout << c[(c.size() - 1) / 2];
	return 0;
}
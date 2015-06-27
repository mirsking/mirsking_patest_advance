#include<iostream>
#include <vector>
using namespace std;


vector<int> decimal2Num(long long num, long long b)
{
	vector<int> res;
	if (num == 0)
		res.push_back(0);
	else
	{
		while (num != 0)
		{
			res.push_back(num%b);
			num = num / b;
		}
	}
	return res;
}

int main()
{
	long long num, b;
	cin >> num >> b;
	vector<int> res = decimal2Num(num, b);
	long long N = res.size();
	bool isPalindromic = true;
	for (long long i = 0; i <= N / 2;i++)
	{
		if (res[i] != res[N - i - 1])
		{
			isPalindromic = false;
			break;
		}
	}
	if (isPalindromic)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	for (long long i = N-1; i >=0; i--)
	{
		cout << res[i];
		if (i != 0)
			cout << ' ';
	}

	return 0;
}
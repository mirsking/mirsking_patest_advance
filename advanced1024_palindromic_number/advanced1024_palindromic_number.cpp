#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;


bool isPalindromic(string str)
{
	int N = str.size();
	for (int i = 0; i < N / 2; i++)
	{
		if (str[i] != str[N-1 - i])
			return false;
	}
	return true;
}

string stringAdd(string& lhs, string& rhs)
{
	string res;

	int llen = lhs.size();
	int rlen = rhs.size();
	int sum = 0, carry = 0;
	for (int i = llen - 1, j = rlen - 1; i >= 0 || j >= 0; i--, j--)
	{
		if (j < 0)
			sum = lhs[i] - '0';
		else if (i < 0)
			sum = rhs[j] - '0';
		else
			sum = lhs[i] - '0' + rhs[j] - '0';
		sum += carry;
		res.insert(res.begin(), sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry != 0)
		res.insert(res.begin(), carry+'0');
	return res;
}



int main()
{
	LL N; int K;
	cin >> N >> K;
	string str = to_string(N);
	if (isPalindromic(str))
	{
		cout << N << endl;
		cout << "0" << endl;
	}
	else
	{
		int i = 0;
		for (; i < K; i++)
		{
			string str_b = str;
			reverse(str.begin(), str.end());
			str = stringAdd(str, str_b);
			if (isPalindromic(str))
				break;
		}
		cout << str << endl;
		cout << min(i + 1, K) << endl;
	}
	return 0;
}
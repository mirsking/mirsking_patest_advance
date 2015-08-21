#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	string str, res;
	cin >> str;
	if (str.size() == 0)
		return 0;
	if (str[0] == '-')
		res.push_back(str[0]); //negative sign

	size_t indexE = str.find('E');
	string num = str.substr(1, indexE - 1);
	string exp = str.substr(indexE + 2, str.size() - indexE - 2);
	LL exp_num = stol(exp);

	if (exp_num == 0)
	{
		cout << res << num;
		return 0;
	}

	char exp_sign = str[indexE+1];
	if (exp_sign == '+')
	{
		if (exp_num < num.size() - 2)
			res = res + num[0] + num.substr(2, exp_num) + '.' + num.substr(exp_num + 2, num.size() - 2 - exp_num);
		else
		{
			res = res + num[0] + num.substr(2, num.size() - 2);
			for (LL i = 0; i < exp_num - num.size() + 2; i++)
				res += '0';
		}
	}
	else if (exp_sign == '-')
	{
		res += "0.";
		while (exp_num-- != 1)
			res += '0';
		res = res + num[0] + num.substr(2, num.size() - 2);
	}

	cout << res;

	return 0;
}
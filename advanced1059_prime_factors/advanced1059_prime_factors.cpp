#include<iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;


string output(map<LL, LL>& factors)
{
	string res;
	for (auto& fac : factors)
	{
		if (fac.second == 1)
			res += to_string(fac.first);
		else
			res += to_string(fac.first) + "^" + to_string(fac.second);
		res += "*";
	}
	res.pop_back();
	return res;
}

int main()
{
	LL num;
	cin >> num;
	map<LL, LL> res;
	if (num != 1)
	{
		bool finish_flag = false;
		LL tmp_num = num;
		LL last_res = 2;
		while (!finish_flag)
		{
			LL i;
			for (i = last_res; i <= sqrt(tmp_num); i++)
			{
				if (tmp_num%i == 0)
				{
					if (res.find(i) != res.end())
						res[i] += 1;
					else
						res[i] = 1;
					tmp_num /= i;
					last_res = i;
					break;
				}
			}
			if (i > sqrt(tmp_num))
			{
				if (res.find(tmp_num) != res.end())
					res[tmp_num] += 1;
				else
					res[tmp_num] = 1;
				finish_flag = true;
			}

		}
	}
	else
	{
		res[1] = 1;
	}
		
	cout << num << "=" << output(res) << endl;
	return 0;
}
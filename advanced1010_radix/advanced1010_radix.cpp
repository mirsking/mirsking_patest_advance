#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* abcdefg*/
long long convert2Dec(string str, long long radix)
{
	long long res = 0;
	//radix = (radix >= 'a'&& radix <= 'z') ? (radix - 'a' + 10+1) : radix+1;
	for (int i = 0; i < str.size(); i++)
	{
		long long val = (str[i] >= 'a'&& str[i] <= 'z') ? str[i] - 'a'+10 : str[i] - '0';
		res = res * radix + val;
	}
	return res;
};

int main(int argc, char** argv)
{
	string a, b;
	int tag;
	long long radix;
	cin >> a >> b >> tag >> radix;
	string aa, bb;
	if (tag == 1)
	{
		aa = a;
		bb = b;
	}
	else if (tag == 2)
	{
		aa = b;
		bb = a;
	}

	long long real_val = convert2Dec(aa, radix);

	// find bb min radix
	long long min_radix = 2;
	for (int i = 0; i < bb.size(); i++)
	{
		long long val = (bb[i] >= 'a'&& bb[i] <= 'z') ? bb[i] - 'a'+10 : bb[i] - '0';
		min_radix = (min_radix < val+1) ? val+1 : min_radix;
	}

	long long got_radix = -100;
	long long L = min_radix;
	long long R = max<long long>(min_radix, real_val+1);
	long long M;
	while (L<=R)
	{
		M = (L + R) / 2;
		long long got_val = convert2Dec(bb, M);
		if (real_val == got_val)
		{
			got_radix = M;
			break;
		}
		else if (got_val < 0 ||real_val < got_val)
		{
			R = M - 1;
		}
		else if (real_val > got_val)
		{
			L = M + 1;
		}

	}
	if (got_radix != -100)
		cout << got_radix;
	else
		cout << "Impossible";

	return 0;
}
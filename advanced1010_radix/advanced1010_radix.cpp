#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* abcdefg*/
long long convert2Dec(string str, int radix)
{
	long long res = 0;
	//radix = (radix >= 'a'&& radix <= 'z') ? (radix - 'a' + 10+1) : radix+1;
	for (int i = 0; i < str.size(); i++)
	{
		int val = (str[i] >= 'a'&& str[i] <= 'z') ? str[i] - 'a'+10 : str[i] - '0';
		res = res * radix + val;
	}
	return res;
};

int main(int argc, char** argv)
{
	string a, b;
	int tag, radix;
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
	int min_radix = 2;
	for (int i = 0; i < bb.size(); i++)
	{
		int val = (bb[i] >= 'a'&& bb[i] <= 'z') ? bb[i] - 'a'+10 : bb[i] - '0';
		min_radix = (min_radix < val+1) ? val+1 : min_radix;
	}

	int got_radix = -100;
	for (int i = min_radix; i <= 36; i++)
	{
		if (real_val == convert2Dec(bb, i))
		{
			got_radix = i;
			break;
		}
	}
	if (got_radix != -100)
		cout << got_radix;
	else
		cout << "Impossible";

	return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef long long LL;

string num2char[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	string str;
	cin >> str;

	LL sum = 0;
	vector<int> res;
	for (LL i = str.size() - 1; i >= 0; i--)
		sum += (str[i]-'0');

	if (sum != 0)
	{
		while (sum != 0)
		{
			res.push_back(sum % 10);
			sum = sum / 10;
		}

		for (int i = res.size() - 1; i >= 0; i--)
		{
			cout << num2char[res[i]];
			if (i != 0)
				cout << ' ';
		}
	}
	else
		cout << num2char[0];
	return 0;
}
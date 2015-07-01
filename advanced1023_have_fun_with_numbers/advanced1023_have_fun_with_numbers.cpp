#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


string doubleBigNum(string num)
{
	string res(num);
	int carry = 0;
	for (int i = num.size() - 1; i >= 0;i--)
	{
		res[i] = num[i] + num[i] - '0' + carry;
		carry = (res[i] - '0') / 10;
		res[i] = (res[i] - '0') % 10 + '0';
	}
	if (carry != 0)
		res.insert(res.begin(), carry + '0');
	return res;
}

bool isok(string num1, string num2)
{
	if (num1.size() != num2.size())
		return false;

	unordered_multiset<char> dict;
	for (int i = 0; i < num1.size(); i++)
		dict.insert(num1[i]);
	for (int i = 0; i < num2.size(); i++)
	{
		auto it = dict.find(num2[i]);
		if (it == dict.end())
			return false;
		else
			dict.erase(it);
	}
	return true;
}

int main()
{
	string num;
	cin >> num;
	string num2 = doubleBigNum(num);
	if (isok(num, num2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << num2 << endl;
	return 0;
}
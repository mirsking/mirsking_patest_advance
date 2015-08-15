#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getReverse(int& num)
{
	//sort the num
	string tmp = to_string(num);
	int len = tmp.size();
	for (int i = 0; i < 4 - len; i++)
		tmp.push_back('0');
	sort(tmp.rbegin(), tmp.rend());
	num = stoi(tmp);
	string reverse_num;
	for (auto& c : tmp)
		reverse_num.insert(reverse_num.begin(), c);
	int res = stoi(reverse_num);
	return res;
}

int main()
{
	int num;
	cin >> num;
	int num2 = getReverse(num);
	if (num == num2)
	{
		printf("%04d - %04d = %04d\n", num, num2, 0);
	}
	else
	{
		while (num - num2 != 6174)
		{
			printf("%04d - %04d = %04d\n", num, num2, num-num2);
			num = num - num2;
			num2 = getReverse(num);
		}
		printf("%04d - %04d = %04d\n", num, num2, num - num2);
	}
	return 0;

}
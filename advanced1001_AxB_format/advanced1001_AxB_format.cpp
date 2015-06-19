// advance1001_AxB_format.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int a, b;
	cin >> a >> b;
	long long sum = a + b;

	if (sum == 0)
		cout << sum;
	else
	{
		long long tmp1, tmp2;
		tmp1 = abs(sum);
		vector<int> v;
		while (tmp1 != 0)
		{
			tmp2 = tmp1 % 1000;
			v.push_back(tmp2);
			tmp1 = tmp1 / 1000;
		}

		if (sum < 0)
			cout << '-';


		for (auto iter = v.rbegin(); iter != v.rend(); iter++)
		{
			if (iter == v.rbegin())
				cout << *iter;
			else
				printf("%03d", *iter);
			if (iter != v.rend() - 1)
				cout << ',';
		}

	}
	return 0;
}


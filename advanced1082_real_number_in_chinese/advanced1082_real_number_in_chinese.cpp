#include <iostream>
#include <string>
#include <vector>
using namespace std;

string CH[] = {"Ge", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
string NUM[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};


int main()
{
	int num;
	cin >> num;
	vector<string> res;

	if (num < 0)
		res.push_back("Fu");
	if (num == 0)
		res.push_back(NUM[0]);
	else
	{
		num = abs(num);
		int r = 100000000;
		int index = 8;
		bool pushed_zero = false;
		while (num != 0)
		{
			int wei = num / r;
			num = num%r;
			if (wei != 0)
			{
				res.push_back(NUM[wei]);
				if (index!=0)//ge
					res.push_back(CH[index]);
				pushed_zero = false;
			}
			else if (!(res.size()==0 || (res.size()==1&&res[0]=="-")))
			{
				if (pushed_zero == false)
				{
					res.push_back(NUM[0]);
					pushed_zero = true;
				}
				if (index == 4)
				{
					if (pushed_zero == true)
						res.pop_back();
					res.push_back(CH[index]);
					pushed_zero = false;
				}
			}
			index--;
			r /= 10;
		}
	}


	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it;
		if (it != res.end() - 1)
			cout << " ";
	}
	

	return 0;
}
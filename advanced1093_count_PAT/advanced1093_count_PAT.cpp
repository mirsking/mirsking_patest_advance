#include <iostream>
#include <string>
using namespace std;

typedef  long long LL;
const LL NUM = 1000000007;

int main()
{
	string str;
	cin >> str;
	LL P_num = 0, T_num = 0;
	LL sum = 0;

	int N = str.size();
	// get all T num
	for (int i = 0; i < N; i++)
	{
		if (str[i] == 'T')
			T_num++;
	}

	for (int i = 0; i < N; i++)
	{
		switch (str[i])
		{
		case 'P':P_num++; break;
		case 'A':sum += P_num*T_num; break;
		case 'T':T_num--; break;
		}
	}
	cout << sum%NUM;
	return 0;
}
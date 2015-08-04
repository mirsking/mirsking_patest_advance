#include <iostream>
#include <string>
using namespace std;

string longestSymStr(string str)
{
	int n = str.length();
	bool dp[1000][1000];
	int max_len = 1;
	int max_begin = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = true;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (str[i] == str[i + 1])
		{
			dp[i][i + 1] = true;
			max_len = 2;
			max_begin = i;
		}
	}

	for (int len = 3; len <= n; len++)
	{
		for (int i = 0; i < n - len + 1; i++)
		{
			int j = i + len - 1;
			if (str[i] == str[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				max_len = len;
				max_begin = i;
			}
		}
	}
	return str.substr(max_begin, max_len);

}

int main()
{
	string str;
	getline(cin, str);
	cout << longestSymStr(str).size();
	return 0;
}
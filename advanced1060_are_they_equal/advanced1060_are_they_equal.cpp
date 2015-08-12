#include <iostream>
#include <string>
using namespace std;

bool isSame(string& str1, string& str2, int N)
{
	int str1_offset = 0, str2_offset = 0;
	for (int i = 0; i < N; i++)
	{
		char a,b;
		if (i+str1_offset >= str1.size())
			a = '0';
		else
		{
			if (str1[i + str1_offset] == '.')
				str1_offset += 1;
			a = str1[i+str1_offset];
		}
		if (i+str2_offset >= str2.size())
			b = '0';
		else
		{
			if (str2[i + str2_offset] == '.')
				str2_offset += 1;
			b = str2[i + str2_offset];
		}

		if (a != b)
			return false;
	}
	return true;
}

string ScienceNum(string& str, int N)
{
	if (str.size() == 0)
		return str;
	if (N == 0)
		return "";

	string res = "0.";
	int num_offset = 0, prime_offset = 0;
	if (str[0] == '0' || str[0] == '.')
	{
		num_offset += 1;
		prime_offset += 1;
	}
	for (int i = 0; i < N; i++)
	{
		char a;
		if (i + num_offset >= str.size())
			a = '0';
		else
		{
			if (str[i + num_offset] == '.')
				num_offset += 1;
			a = str[i + num_offset];
		}
		res.push_back(a);
	}
	
	int n = 0;
	size_t it = str.find('.');
	if (it == string::npos)
		n = str.size();
	else
		n = it;
	n -= prime_offset;
	//if (n != 0)
	{
		res += "*10^";
		res += to_string(n);
	}
	return res;
}

int main()
{
	int N;
	string str1, str2;
	cin >> N;
	cin >> str1 >> str2;

	if (isSame(str1, str2, N))
	{
		cout << "YES ";
		cout << ScienceNum(str1, N);
	}
	else
	{
		cout << "NO ";
		cout << ScienceNum(str1, N);
		cout << " ";
		cout << ScienceNum(str2, N);
	}
	return 0;
}
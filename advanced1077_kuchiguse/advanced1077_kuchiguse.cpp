#include <iostream>
#include <string>
#include <vector>
using namespace std;

string commSuffix(const string& lhs, const string& rhs)
{
	string res = "";
	for (auto lit = lhs.rbegin(), rit = rhs.rbegin(); lit != lhs.rend() && rit != rhs.rend(); lit++, rit++)
	{
		if (*lit == *rit)
			res.insert(res.begin(), *lit);
		else
			break;
	}
	return res;
}


int main()
{
	int N;
	string tmp;
	getline(cin, tmp);
	N = stoi(tmp);
	vector<string> strs(N);
	for (int i = 0; i < N; i++)
	{
		getline(cin, strs[i]);
	}
	
	string suffix = strs[0];
	for (int i = 1; i < N; i++)
	{
		suffix = commSuffix(suffix, strs[i]);
	}

	if (suffix == "")
		cout << "nai" << endl;
	else
		cout << suffix << endl;
	return 0;

}
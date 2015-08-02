#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool lessStr(const string& lhs, const string& rhs)
{
	if (lhs.size() > rhs.size())
		return !lessStr(rhs, lhs);

	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] < rhs[i])
			return true;
		else if (lhs[i] > rhs[i])
			return false;
	}
	if (lhs.size() == rhs.size())
		return false;
	else
	{
		auto rhs_sub = rhs.substr(lhs.size(), rhs.size() - lhs.size());
		return lessStr(lhs, rhs_sub);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<string> strs;
	while (N--)
	{
		string tmp; cin >> tmp;
		strs.push_back(tmp);
	}
	sort(strs.begin(), strs.end(), lessStr);
	bool convert_flag = true;
	if (strs.size() != 0)
	{
		for (auto it = strs.begin(); it != strs.end(); it++)
		{
			int tmp;
			if (convert_flag == true)
			{
				tmp = stoi(*it);
				if (tmp == 0 && it!=strs.end()-1)
				{
					convert_flag = true;
				}
				else
				{
					cout << tmp;
					convert_flag = false;
				}
			}
			else
				cout << *it;
		}
			
	}
	return 0;
}
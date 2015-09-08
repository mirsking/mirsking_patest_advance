#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	unordered_map<char, int> need_counts;
	for (auto& c : str2)
	{
		if (need_counts.find(c) != need_counts.end())
			need_counts[c] ++;
		else
			need_counts[c] = 1;
	}

	for (auto& c : str1)
	{
		if (need_counts.find(c) != need_counts.end())
			need_counts[c] -= 1;
	}

	int less = 0;
	for (auto& m : need_counts)
	{
		if (m.second > 0)
			less += m.second;
	}
	if (less > 0)
		cout << "No " << less;
	else
		cout << "Yes " << str1.size() - str2.size();
	return 0;
}
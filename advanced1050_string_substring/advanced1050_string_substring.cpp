#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	unordered_set<char> chars;
	for (char& c : str2)
		chars.insert(c);

	string res;
	for (auto& c : str1)
	{
		if (chars.find(c) == chars.end())
			res.push_back(c);
	}
	cout << res;
	return 0;
}
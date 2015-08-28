#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	unordered_set<char> bkeys;
	vector<char> res;
	for (int i = 0, j = 0; i < a.size(); i++)
	{
		char c = a[i];
		if ('a' <= c && c <= 'z')
			c = a[i] + 'A' - 'a';
		if (bkeys.find(c) != bkeys.end())
			continue;

		
		char d = b[j];
		if ('a' <= d && d <= 'z')
			d = b[j] + 'A' - 'a';
		if (j < b.size() && c == d)
			j++;
		else
		{
			bkeys.insert(c);
			res.push_back(c);
		}
	}

	for (auto& c : res)
		cout << c;

	return 0;

}
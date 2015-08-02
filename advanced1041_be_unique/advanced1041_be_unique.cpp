#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	typedef long long LL;
	LL N;
	cin >> N;
	unordered_set<LL> bets, winner;
	vector<LL> inputs;
	while (N--)
	{
		LL tmp;
		cin >> tmp;
		inputs.push_back(tmp);
		if (bets.find(tmp) != bets.end())
			continue;
		if (winner.find(tmp) != winner.end())
		{
			bets.insert(tmp);
			winner.erase(tmp);
		}
		else
			winner.insert(tmp);
	}
	if (winner.size() == 0)
		cout << "None";
	else
	{
		for (auto& a : inputs)
		{
			if (winner.find(a) != winner.end())
			{
				cout << a;
				break;
			}
		}
	}
	return 0;
}
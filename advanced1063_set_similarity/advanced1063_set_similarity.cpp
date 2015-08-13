#include <iostream>
#include <set>
#include <vector>
using namespace std;

float getSimilarity(set<int>& lhs, set<int>& rhs)
{
	int same_count = 0;
	for (auto& l : lhs)
	{
		if (rhs.find(l) != rhs.end())
			same_count++;
	}
	return float(same_count) / float(lhs.size() + rhs.size() - same_count);
}

int main()
{
	int N; cin >> N;
	vector<set<int>> sets;
	while (N--)
	{
		int M; cin >> M;
		set<int> set;
		while (M--)
		{
			int tmp; cin >> tmp;
			set.insert(tmp);
		}
		sets.push_back(set);
	}

	int NN; cin >> NN;
	while (NN--)
	{
		int a, b;
		cin >> a >> b;
		printf("%.1f%%\n", getSimilarity(sets[a-1], sets[b-1])*100);
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	int n; double price, rate;
	cin >> n >> price >> rate;
	int root = 0;
	vector<vector<int>> seqs(n);
	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		if (tmp == -1)
			root = i;
		else
			seqs[tmp].push_back(i);
	}

	//BFS
	queue<int> cur, next;
	cur.push(root);
	int layor = 0;
	int count = 0;
	while (!cur.empty())
	{
		layor++;
		count = cur.size();
		while (!cur.empty())
		{
			int tmp = cur.front();
			cur.pop();
			for (auto& c : seqs[tmp])
				next.push(c);
		}
		swap(cur, next);
	}

	double t_price = price*pow(1 + rate / 100.0, layor-1);
	printf("%.2lf %d", t_price, count);
	return 0;
}
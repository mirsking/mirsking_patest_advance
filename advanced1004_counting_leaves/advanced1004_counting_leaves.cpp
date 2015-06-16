#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void countLeaves(vector<vector<int> >& vec, vector<int>& que, vector<int>& res)
{
	if (que.size() == 0)
		return;
	
	int count = 0;
	for (int i = 0; i < que.size();i++)
	{
		if (vec[que[i]].size() == 0)
			count++;
	}
	res.push_back(count);

	vector<int> que1;
	for (int i = 0; i < que.size(); i++)
	{
		for (int j = 0; j < vec[que[i]].size(); j++)
			que1.push_back(vec[que[i]][j]);
	}
	countLeaves(vec, que1, res);
}

int main(int argc, char** argv)
{
	int N, M;
	cin >> N >> M;

	vector< vector< int> > ped_tree;
	ped_tree.resize(N);

	for (int i = 0; i < M; i++)
	{
		int node; cin >> node;
		auto& v = ped_tree[node-1];
		int num; cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> node;
			v.push_back(node-1);
		}
	}


	vector<int> que;
	if (ped_tree[0].size() > 0)
	{
		que.push_back(0);
	}
	vector<int> res;
	int count = 0;
	countLeaves(ped_tree, que, res);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if ((i + 1) != res.size())
			cout << ' ';
	}

	if (res.size() == 0)
		cout << N;

	return 0;
}
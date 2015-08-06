#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Tree{
	vector<LL> weights;
	vector<vector<LL>> sons;
	LL N, n_non_leaf;
	LL desire_weight;
};

void getR2L(const Tree& tree, LL root, LL& cur_weights, vector<LL>& cur_path, vector<vector<LL>>& res)
{
	cur_path.push_back(tree.weights[root]);
	cur_weights += tree.weights[root];

	if (cur_weights > tree.desire_weight)
		return;

	else if (cur_weights == tree.desire_weight)
	{
		if (tree.sons[root].size() == 0)// leaf node
		{
			res.push_back(cur_path);
			return;
		}
	}

	for (auto it = tree.sons[root].rbegin(); it != tree.sons[root].rend(); it++)
	{
		getR2L(tree, *it, cur_weights, cur_path, res);
		cur_weights -= tree.weights[*it];	// after test the subtree, pop the turning node
		cur_path.pop_back();
	}
}

bool compare(const vector<LL>& lhs, const vector<LL>& rhs)
{
	for (auto lit = lhs.begin(), rit = rhs.begin();
		lit!=lhs.end(),	rit != rhs.end(); lit++, rit++)
	{
		if (*lit > *rit)
			return false;
		else if (*lit < *rit)
			return true;
	}
	if (lhs.size() == rhs.size())
		return false;// equal should return false in std::stl
	else
		return true;
}

int main()
{
	Tree tree;
	cin >> tree.N >> tree.n_non_leaf >> tree.desire_weight;
	tree.weights.resize(tree.N);
	tree.sons.resize(tree.N);

	for (LL i = 0; i < tree.N; i++)
	{
		cin >> tree.weights[i];
	}

	for (int i = 0; i < tree.n_non_leaf; i++)
	{
		LL ID, K; cin >> ID >> K;
		for (LL i = 0; i < K; i++)
		{
			LL tmp; cin >> tmp;
			tree.sons[ID].push_back(tmp);
		}
	}

	LL cur_weights = 0;
	vector<LL> cur_path;
	vector<vector<LL>> res;
	getR2L(tree, 0, cur_weights, cur_path, res);
	sort(res.rbegin(), res.rend(), compare);

	for (auto& r : res)
	{
		for (auto it = r.begin(); it != r.end(); it++)
		{
			cout << *it;
			if (it != r.end() - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
	
}
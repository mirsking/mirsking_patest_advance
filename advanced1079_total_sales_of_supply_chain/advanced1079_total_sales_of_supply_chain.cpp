#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

double price, rate;

struct TreeNode
{
	int id;
	vector<TreeNode*> sons;
	int layor;
	bool is_leaf;
	int sum;
	TreeNode(int val) :id(val), layor(0), is_leaf(false), sum(0){}
};

TreeNode* buildChain(const vector<vector<int>>& chains, const vector<int>& sums, int id)
{
	TreeNode* root = new TreeNode(id);
	if (sums[id] > 0)
	{
		root->sum = sums[id];
		root->is_leaf = true;
	}

	for (auto& c : chains[id])
	{
		TreeNode* child = buildChain(chains, sums, c);
		if (child!=nullptr)
			root->sons.push_back(child);
	}
	return root;
}

void BFS(deque<TreeNode*> que, int& layor, double& sum)
{
	if (que.empty())
		return;

	layor++;
	auto front = que.front();
	auto last = que.back();
	do{
		front = que.front();
		que.pop_front();
		for (auto& c : front->sons)
		{
			c->layor = layor;
			que.push_back(c);
			if (c->is_leaf == true)
				sum += (price*pow(1+rate/100, c->layor)*c->sum);
		}
	} while (front != last);
	BFS(que, layor, sum);
}

int main()
{
	int n;
	cin >> n >> price >> rate;

	vector<vector<int>> chains(n);
	vector<int> sums(n);
	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		chains[i].resize(m);
		if (m == 0)
		{
			int sum; cin >> sum;
			sums[i] = sum;
		}
		else
		{
			for (int j = 0; j < m; j++)
				cin >> chains[i][j];
		}
	}
	TreeNode* root = buildChain(chains, sums, 0);
	if (root == nullptr)
		return 0;

	double sum = 0;
	if (root->sons.empty())
	{
		//test point 2
		//1 1 1
		//0 9
		if (root->is_leaf)
			sum += (price*pow(1+rate/100, root->layor)*root->sum);
	}
	else
	{
		int layor = 0;
		deque<TreeNode*> que;
		que.push_back(root);
		BFS(que, layor, sum);
	}
	printf("%.1lf", sum);
	return 0;

}
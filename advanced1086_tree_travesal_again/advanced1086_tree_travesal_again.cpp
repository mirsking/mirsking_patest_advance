#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
	int key;
	TreeNode *left, *right;
	TreeNode(int v) :key(v), left(nullptr), right(nullptr){}
};

template <typename BidiIt>
TreeNode* buildTree(BidiIt pre_left, BidiIt pre_right, BidiIt order_left, BidiIt order_right)
{
	if (pre_left == pre_right)
		return nullptr;
	if (order_left == order_right)
		return nullptr;

	auto root_val = *pre_left;
	auto root = new TreeNode(root_val);
	auto order_root_pos = find(order_left, order_right, root_val);
	auto left_size = distance(order_left, order_root_pos);

	root->left = buildTree(next(pre_left), next(pre_left, left_size+1), order_left, next(order_left, left_size));
	root->right = buildTree(next(pre_left, left_size + 1), pre_right, next(order_root_pos), order_right);
	return root;
}

void postTravesal(TreeNode* root, vector<int>& res)
{
	if (root == nullptr)
		return;

	postTravesal(root->left, res);
	postTravesal(root->right, res);
	res.push_back(root->key);
}

//根据输入确定前序遍历和中序遍历，然后建树
int main()
{
	int n;
	cin >> n;

	vector<int> pre_travesal, order_travesal;
	stack<int> sta;
	string cmd;
	while (cin>>cmd)
	{
		int val;
		switch (cmd[1])
		{
		case 'u': cin >> val; sta.push(val); pre_travesal.push_back(val); break;
		case 'o': val = sta.top(); sta.pop(); order_travesal.push_back(val); break;
		}
	}
	TreeNode* root = buildTree(pre_travesal.begin(), pre_travesal.end(), order_travesal.begin(), order_travesal.end());

	vector<int> res;
	postTravesal(root, res);
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it;
		if (it != res.end() - 1)
			cout << " ";
	}
	return 0;
}
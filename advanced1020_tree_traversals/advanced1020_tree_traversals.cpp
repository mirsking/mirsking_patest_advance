#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//template<typename BidiIt>
typedef vector<int>::iterator BidiIt;
TreeNode* buildTree(BidiIt post_first, BidiIt post_last, BidiIt in_first, BidiIt in_last)
{
	if (post_first >= post_last)
		return nullptr;
	if (in_first >= in_last)
		return nullptr;

	auto val = *prev(post_last);
	TreeNode* root = new TreeNode(val);

	auto root_in_pose = find(in_first, in_last, val);
	auto left_size = distance(in_first, root_in_pose);
	auto post_left_last = next(post_first, left_size);

	root->left = buildTree(post_first, post_left_last, in_first, root_in_pose);
	root->right = buildTree(post_left_last, prev(post_last), next(root_in_pose), in_last);

	return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder)
{
	return buildTree(postorder.begin(), postorder.end(),
		inorder.begin(), inorder.end());
}


vector<int> levelOrderTraversal(TreeNode* root)
{
	vector<int> res;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		TreeNode* root = que.front();
		if (root != nullptr)
		{
			res.push_back(root->val);
			que.pop();
			if (root->left != nullptr)
				que.push(root->left);
			if (root->right != nullptr)
				que.push(root->right);
		}
		else
			que.pop();
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> postorder, inorder, levelorder;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		postorder.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		inorder.push_back(tmp);
	}

	TreeNode* root = buildTree(postorder, inorder);
	levelorder = levelOrderTraversal(root);
	for (int i = 0; i < levelorder.size(); i++)
	{
		cout << levelorder[i];
		if (i != levelorder.size() - 1)
			cout << ' ';
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

int findLayor(int n)
{
	return log(n + 1)/log(2);
}


/*
1. 如果总元素数目N 刚好能构成layor层满树，则中间的元素一定是 full_layor_N/2;
2. 如果总元素数目N 超过 full_layor_N， 则中间的元素是 1中的位置加上两者之差
3. 如果2中计算出的数目大于了补全元素后满树元素个数的一半， 则中间位置取一半
*/
template<typename BidiIt>
TreeNode* buildCBT(BidiIt left, BidiIt right)
{
	if (left >= right)
		return nullptr;

	int N = right - left;
	int layor = findLayor(N);
	int full_layor_N = pow(2, layor) - 1;
	int mid = full_layor_N / 2 + N - full_layor_N;

	int full_layor_1_N = pow(2, layor + 1) - 1;
	if (mid > full_layor_1_N / 2)
		mid = full_layor_1_N/2;

	TreeNode* root = new TreeNode(*(left + mid));
	root->left = buildCBT(left, left + mid);
	root->right = buildCBT(left + mid + 1, right);
	return root;
}

void LevelOrderTravesal(TreeNode* node, vector<TreeNode*>& res)
{
	if (node == nullptr)
		return;
	res.clear();
	queue<TreeNode*> que;
	que.push(node);
	while (!que.empty())
	{
		auto& node_ptr = que.front();
		res.push_back(que.front());
		if (node_ptr->left != nullptr)
			que.push(node_ptr->left);
		if (node_ptr->right != nullptr)
			que.push(node_ptr->right);
		que.pop();
	}
}


int main()
{
	int N;
	cin >> N;
	vector<int> vals;
	vals.resize(N);
	for (int i = 0; i < N; i++)
		cin >> vals[i];
	sort(vals.begin(), vals.end());
	TreeNode* root = buildCBT(vals.begin(), vals.end());
	vector<TreeNode*> res;
	LevelOrderTravesal(root, res);
	for (auto it = res.begin(); it != res.end();it++)
	{
		cout << (*it)->val;
		if (it + 1 != res.end())
			cout << " ";
	}
	return 0;
}

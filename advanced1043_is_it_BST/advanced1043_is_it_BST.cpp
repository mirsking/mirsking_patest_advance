#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(nullptr), right(nullptr){};
};

TreeNode* creatTreeByPreOrder(vector<int>& vec, bool mirror_flag, bool& rtn_flag)
{
	if (vec.size() == 0)
		return nullptr;

	TreeNode* root = new TreeNode(vec[0]);
	vector<int> left, right;
	if (mirror_flag == false)
	{
		size_t index = 1;
		for (; index < vec.size(); index++)
		{
			if (vec[index] < root->val)
				left.push_back(vec[index]);
			else
				break;
		}
		for (; index < vec.size(); index++)
		{
			if (vec[index] >= root->val)
				right.push_back(vec[index]);
			else
				break;
		}
	}
	else
	{
		size_t index = 1;
		for (; index < vec.size(); index++)
		{
			if (vec[index] >= root->val)
				left.push_back(vec[index]);
			else
				break;
		}
		for (; index < vec.size(); index++)
		{
			if (vec[index] < root->val)
				right.push_back(vec[index]);
			else
				break;
		}
	}
	if (left.size() + right.size() != vec.size() - 1)
	{
		rtn_flag = false;
		return nullptr;
	}
	else
	{
		root->left = creatTreeByPreOrder(left, mirror_flag, rtn_flag);
		root->right= creatTreeByPreOrder(right, mirror_flag, rtn_flag);
		rtn_flag = true;
		return root;
	}
		
}


TreeNode* creatTreeByPreOrder(vector<int>& vec, bool& rtn_flag)
{
	TreeNode* root = creatTreeByPreOrder(vec, false, rtn_flag);
	if (rtn_flag == true)
		return root;
	else
	{
		TreeNode* root = creatTreeByPreOrder(vec, true, rtn_flag);
		if (rtn_flag == true)
			return root;
		else
			return nullptr;
	}
}

void postOrderTravesal(TreeNode* root, vector<int>& vec)
{
	if (root == nullptr)
		return;
	else
	{
		postOrderTravesal(root->left, vec);
		postOrderTravesal(root->right, vec);
		vec.push_back(root->val);
	}
}

int main()
{
	int N;
	vector<int> vec;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N;i++)
		cin >> vec[i];
	bool rtn_flag = false;
	TreeNode* root = creatTreeByPreOrder(vec, rtn_flag);
	if (rtn_flag == false)
	{
		cout << "NO";
	}
	else
	{
		vector<int> res;
		postOrderTravesal(root, res);
		cout << "YES" << endl;
		for (auto it = res.begin(); it != res.end(); it++)
		{
			cout << *it;
			if (it != res.end() - 1)
				cout << " ";
		}
	}
	
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(nullptr), right(nullptr){};
};

void insertNode(TreeNode* &root, int val)
{
	if (root == nullptr)
		root = new TreeNode(val);
	else
	{
		if (val >= root->val)
			insertNode(root->right, val);
		else
			insertNode(root->left, val);
	}
}

void creatTree(vector<int>& vec, TreeNode* &root)
{
	for (int i = 0; i < vec.size(); i++)
	{
		insertNode(root, vec[i]);
	}
}

void preOrderTravesal(TreeNode* root, vector<int>& vec, bool mirror_flag)
{
	if (root == nullptr)
		return;
	else
	{
		vec.push_back(root->val);
		if (mirror_flag == true)
		{
			preOrderTravesal(root->right, vec, mirror_flag);
			preOrderTravesal(root->left, vec, mirror_flag);
		}
		else
		{
			preOrderTravesal(root->left, vec, mirror_flag);
			preOrderTravesal(root->right, vec, mirror_flag);
		}
	}
}

void postOrderTravesal(TreeNode* root, vector<int>& vec, bool mirror_flag)
{
	if (root == nullptr)
		return;
	else
	{
		if (mirror_flag == true)
		{
			postOrderTravesal(root->right, vec, mirror_flag);
			postOrderTravesal(root->left, vec, mirror_flag);
		}
		else
		{
			postOrderTravesal(root->left, vec, mirror_flag);
			postOrderTravesal(root->right, vec, mirror_flag);
		}
		vec.push_back(root->val);
	}
}

int main()
{
	int N;
	vector<int> vec;
	cin >> N;
	vec.resize(N);
	TreeNode* root = nullptr;
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
		insertNode(root, vec[i]);
	}
	//creatTree(vec, root);
	vector<int> vec2;

	preOrderTravesal(root, vec2, false);
	if (vec2 == vec)
	{
		vec2.clear();
		postOrderTravesal(root, vec2, false);
		cout << "YES" << endl;
		for (auto it = vec2.begin(); it != vec2.end(); it++)
		{
			cout << *it;
			if (it != vec2.end() - 1)
				cout << " ";
		}
	}
	else
	{
		vec2.clear();
		preOrderTravesal(root, vec2, true);
		if (vec2 == vec)
		{
			vec2.clear();
			postOrderTravesal(root, vec2, true);
			cout << "YES" << endl;
			for (auto it = vec2.begin(); it != vec2.end(); it++)
			{
				cout << *it;
				if (it != vec2.end() - 1)
					cout << " ";
			}
		}
		else
			cout << "NO";
	}


	return 0;
}
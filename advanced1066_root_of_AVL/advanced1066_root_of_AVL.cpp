#include <iostream>
#include <algorithm>
using namespace std;

template<class V>
class AVLTree{
public:

	struct AVLTreeNode{
		V val;
		int height;
		AVLTreeNode* left;
		AVLTreeNode* right;

		AVLTreeNode(const V& v) :val(v), height(1), left(nullptr), right(nullptr){}
		~AVLTreeNode(){ val.~V(); }
	};


	AVLTree() :root_(nullptr){}

	AVLTreeNode* getRoot()
	{
		return root_;
	}
	void insert(const V& v)
	{
		root_ = insert(root_, v);
	}
private:
	AVLTreeNode* insert(AVLTreeNode* root, const V& v)
	{
		if (root == nullptr)
		{
			root = new AVLTreeNode(v);
			return root;
		}
		else if (root->val > v)
			root->left = insert(root->left, v);
		else if (root->val < v)
			root->right = insert(root->right, v);

		//update height
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

		// rebalance the tree
		int balance = getBalance(root);
		if (balance>1)//left child tree higher
		{
			if (v < root->left->val)// left left case
			{
				return rightRotate(root);
			}
			else // left right case 
			{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		else if (balance < -1)// right child tree higher
		{
			if (v>root->right->val)//right right case 
				return leftRotate(root);
			else// right left case 
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}


	int getHeight(AVLTreeNode* root)
	{
		if (root == nullptr)
			return 0;
		return root->height;
	}
	int getBalance(AVLTreeNode* root)
	{
		if (root == nullptr)
			return 0;
		return getHeight(root->left) - getHeight(root->right);
	}

	AVLTreeNode* rightRotate(AVLTreeNode* root)
	{
		AVLTreeNode* tmp = root->left;
		root->left = tmp->right;
		tmp->right = root;
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
		return tmp;
	}
	AVLTreeNode* leftRotate(AVLTreeNode* root)
	{
		AVLTreeNode* tmp = root->right;
		root->right = tmp->left;
		tmp->left = root;
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
		return tmp;
	}

private:

	AVLTreeNode* root_;
};

int main()
{
	int N; cin >> N;
	AVLTree<int> avl_tree;
	while (N--)
	{
		int val; cin >> val;
		avl_tree.insert(val);
	}
	cout << avl_tree.getRoot()->val;
	return 0;
}
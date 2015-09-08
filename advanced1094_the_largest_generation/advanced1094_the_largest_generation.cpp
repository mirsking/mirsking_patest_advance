#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

struct TreeNode{
	int id;
	vector<TreeNode*> childrens;
	TreeNode(int val) :id(val){}
};

TreeNode* buildTree(const vector<vector<int>>& nodes, int id)
{

	TreeNode* root = new TreeNode(id);
	if (nodes[id].empty())
		return root;

	for (auto& n : nodes[id])
	{
		TreeNode* child = buildTree(nodes, n);
		if (child!=nullptr)
			root->childrens.push_back(child);
	}
	return root;
}

void BFS(deque<TreeNode*>& que, vector<int>& res)
{
	if (que.empty())
		return;
	auto last = que.back();
	auto front = que.front();
	int sum = 0;
	do{
		front = que.front();
		que.pop_front();
		for (auto& c :  front->childrens)
		{
			que.push_back(c);
			sum++;
		}
	} while (front != last);
	res.push_back(sum);
	BFS(que, res);
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> nodes(N + 1);

	for (int i = 0; i < M; i++)
	{
		int id, num;
		cin >> id >> num;
		while (num--)
		{
			int tmp; cin >> tmp;
			nodes[id].push_back(tmp);
		}
	}

	//build tree
	TreeNode* root = buildTree(nodes, 1);

	deque<TreeNode*> que;
	que.push_back(root);
	vector<int> res;
	res.push_back(1);

	BFS(que, res);

	int max_layor = 0;
	int max_num = -1;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i]>max_num)
		{
			max_num = res[i];
			max_layor = i;
		}
	}

	cout << max_num << " " << max_layor+1;

	return 0;
	
}
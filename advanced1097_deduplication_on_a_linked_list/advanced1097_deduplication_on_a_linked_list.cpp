#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode{
	int left;
	int val;
	int right;
};

int main()
{
	vector<ListNode> list, sorted_list, res_list, del_list;
	int index[100000];
	int N, begin;
	cin >> begin >> N;
	if (begin == -1)
		return 0;
	for (int i = 0; i < N; i++)
	{
		ListNode node;
		cin >> node.left >> node.val >> node.right;
		list.push_back(node);
		index[node.left] = i;
	}

	int in = index[begin];
	while (list[in].right != -1)
	{
		sorted_list.push_back(list[in]);
		in = index[list[in].right];
	}
	sorted_list.push_back(list[in]);

	unordered_set<int> nums;
	for (auto it = sorted_list.begin(); it != sorted_list.end(); it++)
	{
		int val = abs(it->val);
		if (nums.find(val) == nums.end())
		{
			nums.insert(val);
			res_list.push_back(*it);
		}
		else
		{
			if (it != sorted_list.begin() && (it+1)!= sorted_list.end())
				res_list.rbegin()->right = (it + 1)->left;

			if (del_list.size() != 0)
				del_list.rbegin()->right = it->left;

			del_list.push_back(*it);
		}
	}

	if (!res_list.empty())
		res_list.rbegin()->right = -1;
	if (!del_list.empty())
		del_list.rbegin()->right = -1;

	for (auto it = res_list.begin(); it != res_list.end(); it++)
	{
		if (it->right!=-1)
			printf("%05d %d %05d\n", it->left, it->val, it->right);
		else
			printf("%05d %d %d\n", it->left, it->val, it->right);
	}

	for (auto it = del_list.begin(); it != del_list.end(); it++)
	{
		if (it->right != -1)
			printf("%05d %d %05d\n", it->left, it->val, it->right);
		else
			printf("%05d %d %d\n", it->left, it->val, it->right);
	}

	return 0;
}
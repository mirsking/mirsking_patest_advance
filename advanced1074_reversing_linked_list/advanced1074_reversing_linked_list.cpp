#include <iostream>
#include <vector>
using namespace std;


struct ListNode{
	int val;
	int left, right;
};

int main()
{
	int begin, N, n;
	cin >> begin >> N >> n;
	vector<int> index;
	index.resize(100000);
	vector<ListNode> list, sorted_list, rev_list;
	for (int i = 0; i < N;i++)
	{
		ListNode node;
		cin >> node.left >> node.val >> node.right;
		list.push_back(node);
		index[node.left] = i;
	}
	while (begin != -1)
	{
		int ind = index[begin];
		ListNode& node = list[ind];
		sorted_list.push_back(node);
		begin = node.right;
	}

	auto begin_it = sorted_list.begin();
	int left = 0, right = n;
	
	while (right <= sorted_list.size())
	{
		for (int it = right - 1; it >= left; it--)
			rev_list.push_back(*(begin_it+it));
		left = right;
		right = right + n;
	}
		
	if (right>sorted_list.size())// right
	{
		// do not reverse
		for (auto it = begin_it + left; it != sorted_list.end(); it++)
			rev_list.push_back(*it);
	}

	for (auto it = rev_list.begin(); it != rev_list.end() - 1; it++)
		it->right = (it + 1)->left;

	rev_list.rbegin()->right = -1;

	for (auto& node : rev_list)
	{
		if (node.right!=-1)
			printf("%05d %d %05d\n", node.left, node.val, node.right);
		else
			printf("%05d %d %d\n", node.left, node.val, node.right);
	}

	return 0;
}
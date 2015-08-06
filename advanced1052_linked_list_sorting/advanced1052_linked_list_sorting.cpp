#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
	int val;
	int left;
	int right;
};

bool compare(const ListNode& lhs, const ListNode& rhs)
{
	return lhs.val < rhs.val;
}

int main()
{
	int N, head;
	cin >> N >> head;
	vector<ListNode> list(N), sorted_list;
	vector<int> list_vals(100000, -1);
	for (int i = 0; i < N; i++)
	{
		ListNode& node = list[i];
		cin >> node.left >> node.val >> node.right;
		list_vals[node.left] = i;
	}

	if (head==-1 || list_vals[head] == -1)// no valid list node
	{
		cout << "0 -1";
		return 0;
	}
	//sort the list by address
	int add = head;
	while (add != -1)
	{
		sorted_list.push_back(list[list_vals[add]]);
		add = list[list_vals[add]].right;
	}

	// sort the list by key
	sort(sorted_list.begin(), sorted_list.end(), compare);

	// fix the address
	for (auto it = sorted_list.begin(); it != sorted_list.end() - 1;it++)
	{
		it->right = (it + 1)->left;
	}
	sorted_list.rbegin()->right = -1;

	cout << sorted_list.size();
	if (sorted_list.size() != 0)
	{
		printf(" %05d\n", sorted_list[0].left);
		for (auto it = sorted_list.begin(); it != sorted_list.end()-1; it++)
		{
			printf("%05d %d %05d\n", it->left, it->val, it->right);
		}
		printf("%05d %d %d\n", sorted_list.rbegin()->left, sorted_list.rbegin()->val, sorted_list.rbegin()->right);
	}
	
	return 0;
}
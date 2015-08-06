#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	int left;
	int right;
};

void insertListNode(vector<ListNode>& list, ListNode& node)
{
	int before_size = list.size();
	for (auto it = list.begin(); it != list.end(); it++)
	{
		if (it->val > node.val)
		{
			list.insert(it, node);
			break;
		}
	}
	if (before_size == list.size())// didn't insert succesfully
		list.push_back(node);
}

int main()
{
	int N, head;
	cin >> N >> head;
	vector<ListNode> list(N), sorted_list, res_list;
	vector<int> list_vals(100000, -1);
	for (int i = 0; i < N; i++)
	{
		ListNode& node = list[i];
		cin >> node.left >> node.val >> node.right;
		list_vals[node.left] = i;
	}

	if (list_vals[head] == -1)// no valid list node
	{
		cout << "0";
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

	// fix the address
	for (auto it = res_list.begin(); it != res_list.end() - 1;it++)
	{
		it->right = (it + 1)->left;
	}
	res_list.rbegin()->right = -1;

	cout << res_list.size();
	if (res_list.size() != 0)
	{
		printf(" %05d\n", res_list[0].left);
		for (auto it = res_list.begin(); it != res_list.end()-1; it++)
		{
			printf("%05d %d %05d\n", it->left, it->val, it->right);
		}
		printf("%05d %d %d\n", res_list.rbegin()->left, res_list.rbegin()->val, res_list.rbegin()->right);
	}
	
	return 0;
}
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct list_node_t{
	int lid;
	char val;
	int rid;
};

void getSortedList(vector<list_node_t>& llist, int begin, vector<list_node_t>& list)
{
	int id = begin;
	while (id != -1)
	{
		list.push_back(llist[id]);
		id = llist[id].rid;
	}
}
int findSuffixBegin(const vector<list_node_t>& list1, const vector<list_node_t>& list2)
{
	//vector<list_node_t>::reverse_iterator it1, it2;
	auto it1 = list1.rbegin(), it2 = list2.rbegin();
	for (it1 = list1.rbegin(), it2 = list2.rbegin();
		it1 != list1.rend(), it2 != list2.rend(); it1++, it2++)
	{
		if ((*it1).lid != (*it2).lid)
			break;
	}
	if (it1 == list1.rbegin())
		return -1;
	else
		return (*(it1 - 1)).lid;
}

int main()
{
	int begin1, begin2, N;
	cin >> begin1 >> begin2>> N;
	vector<list_node_t> list(100000), list1, list2;
	list_node_t list_node;
	while(N--)
	{
		cin >> list_node.lid >> list_node.val >> list_node.rid;
		list[list_node.lid] = list_node;
	}
	getSortedList(list, begin1, list1);
	getSortedList(list, begin2, list2);

	int index = findSuffixBegin(list1, list2);
	if (index == -1)
		printf("-1");
	else
		printf("%5d", index);

	return 0;
}
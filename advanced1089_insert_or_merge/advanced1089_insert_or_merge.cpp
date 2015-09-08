#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSame(const vector<int>& lhs, const vector<int>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return false;
	}

	return true;
}

bool isInsertSort(const vector<int>& pre_seq, const vector<int>& sorted_seq, vector<int>& next_seq)
{
	bool got_flag = false;
	auto seq = pre_seq;
	int n = seq.size();
	for (int i = 1; i < n; i++)
	{
		int tmp = seq[i];
		int j;
		for (j = i; j>0 && seq[j - 1] > tmp; j--)
			seq[j] = seq[j - 1];
		seq[j] = tmp;

		if (got_flag)
		{
			next_seq = seq;
			return true;
		}
		else
			got_flag = isSame(seq, sorted_seq);
	}
	return false;
}


bool isMergeSort(const vector<int>& pre_seq, const vector<int>& sorted_seq, vector<int>& next_seq)
{
	bool got_flag = false;
	int n = pre_seq.size();
	vector<int> merged_seq(n), seq = pre_seq;
	for (int merge_size = 1; merge_size < n; merge_size *= 2)
	{
		for (int start = 0; start < n; start += merge_size * 2)
		{
			int start1 = start, start2 = start + merge_size;
			int end1 = start + merge_size - 1, end2 = start2 + merge_size - 1;

			if (end2 >= n) end2 = n - 1;

			if (end1 >= n - 1)// no seq2 to merge
			{
				for (start1; start1 < n; start1++)
					merged_seq[start1] = seq[start1];
				continue;
			}

			int begin = start;
			for (; start1 <= end1 && start2 <= end2;)
			{
				int a, b;
				a = seq[start1];
				b = seq[start2];
				if (a < b)
				{
					merged_seq[begin++] = a;
					start1++;
				}
				else
				{
					merged_seq[begin++] = b;
					start2++;
				}
			}
			if (start1 > end1)
			{
				for (; start2 <= end2; start2++)
					merged_seq[begin++] = seq[start2];
			}
			else
			{
				for (; start1 <= end1; start1++)
					merged_seq[begin++] = seq[start1];
			}
		}
		seq = merged_seq;
		if (got_flag)
		{
			next_seq = merged_seq;
			return true;
		}
		else
		{
			got_flag = isSame(sorted_seq, merged_seq);
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<int> pre_seq, sorted_seq;
	pre_seq.resize(n);
	sorted_seq.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pre_seq[i];
	for (int i = 0; i < n; i++)
		cin >> sorted_seq[i];
	vector<int> res;

	bool flag = isInsertSort(pre_seq, sorted_seq, res);
	if (flag)
		cout << "Insertion Sort" << endl;
	else
	{
		cout << "Merge Sort" << endl;
		isMergeSort(pre_seq, sorted_seq, res);
	}

	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it;
		if (it != res.end() - 1)
			cout << " ";
	}
	return 0;

}
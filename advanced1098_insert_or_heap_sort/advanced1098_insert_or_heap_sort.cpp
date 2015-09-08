#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> seq_t;

bool isSame(const seq_t& lhs, const seq_t& rhs)
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

bool isInsertSort(const seq_t& pre_seq, const seq_t& sorted_seq, seq_t& next_seq)
{
	bool got_flag = false;
	seq_t seq = pre_seq;
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

inline int leftChild(int i)
{
	return 2 * i + 1;
}

inline int rightChild(int i)
{
	return 2 * i + 2;
}

void percolateDown(seq_t& seq, int i, int n)
{
	if (n <= 1 || i < 0 || i >= n)
		return;

	int max_val;
	while (leftChild(i) < n)
	{
		if (leftChild(i) == n - 1)
			max_val = seq[leftChild(i)];
		else
			max_val = max(seq[leftChild(i)], seq[rightChild(i)]);

		if (seq[i] < max_val)
		{
			if (max_val == seq[leftChild(i)])
			{
				swap(seq[i], seq[leftChild(i)]);
				i = leftChild(i);
			}
			else
			{
				swap(seq[i], seq[rightChild(i)]);
				i = rightChild(i);
			}
		}
		else
			break;
	}
}


bool isHeapSort(const seq_t& pre_seq, const seq_t& sorted_seq, seq_t& next_seq)
{
	bool got_flag = false;
	int n = pre_seq.size();
	seq_t seq = pre_seq;

	// build max heap
	for (int i = n / 2; i >= 0; i--)
		percolateDown(seq, i, n);

	// heap sort
	for (int i = n - 1 ; i > 0; i--)
	{
		swap(seq[0], seq[i]);
		percolateDown(seq, 0, i);
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


int main()
{
	int n; cin >> n;
	seq_t pre_seq(n), sorted_seq(n);
	for (int i = 0; i < n; i++)
		cin >> pre_seq[i];
	for (int i = 0; i < n; i++)
		cin >> sorted_seq[i];

	seq_t res;
	if (isInsertSort(pre_seq, sorted_seq, res))
	{
		cout << "Insertion Sort" << endl;
	}
	else
	{
		cout << "Heap Sort" << endl;
		isHeapSort(pre_seq, sorted_seq, res);
	}

	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it;
		if (it != res.end() - 1)
			cout << " ";
	}
	return 0;
}
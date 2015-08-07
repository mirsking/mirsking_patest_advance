#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct BinTree{
	static const int MAXN = 100001;
	vector<int> vec;

	BinTree(){ vec = vector<int>(MAXN, 0); }

	int lowbit(int x)
	{
		return x&(-x);
	}

	void update(int x, int val)
	{
		while (x <= MAXN)
		{
			vec[x] += val;
			x += lowbit(x);
		}
	}

	int getSum(int x)
	{
		int sum = 0;
		while (x > 0)
		{
			sum += vec[x];
			x -= lowbit(x);
		}
		return sum;
	}

	int findMedian(int val, int l = 0, int r = MAXN - 1)
	{
		if (l == r)
			return l;

		int mid = (l + r) / 2;
		if (getSum(mid) < val)
			return findMedian(val, mid + 1, r);
		else
			return findMedian(val, l, mid);
	}

};

class MyStack
{
public:
	void push(int val)
	{
		sta.push_back(val);
		bin_tree.update(val, 1);
	}
	void pop()
	{
		if (sta.empty())
			cout << "Invalid" << endl;
		else
		{
			cout << *sta.rbegin() << endl;
			bin_tree.update(*sta.rbegin(), -1);
			sta.pop_back();
		}
	}
	void peakMedian()
	{
		if (sta.empty())
			cout << "Invalid" << endl;
		else
		{
			cout << bin_tree.findMedian((sta.size()+1)/2) << endl;
		}
	}
private:
	vector<int> sta;
	BinTree bin_tree;
};


int main()
{
	int N;
	cin >> N;
	MyStack sta;
	while (N--)
	{
		string str;
		cin >> str;
		switch (str[1])
		{
			case 'o':
				sta.pop();
				break;
			case 'e':
				sta.peakMedian();
				break;
			case 'u':
			{
				int val; cin >> val;
				sta.push(val);
				break;
			}
		}
	}
	return 0;
}
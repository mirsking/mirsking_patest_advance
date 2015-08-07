#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class MyStack
{
public:
	void push(int val)
	{
		sta.push_back(val);
		vec.push_back(val);
	}
	void pop()
	{
		if (sta.empty())
			cout << "Invalid" << endl;
		else
		{
			cout << *sta.rbegin() << endl;
			sta.pop_back();
			vec.pop_back();
		}
	}
	void peakMedian()
	{
		if (sta.empty())
			cout << "Invalid" << endl;
		else
		{
			sort(vec.begin(), vec.end());
			cout << vec[(vec.size() - 1) / 2] << endl;
		}
	}
private:
	vector<int> sta;
	vector<int> vec;
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
		if (str == "Pop")
			sta.pop();
		else if (str == "PeekMedian")
			sta.peakMedian();
		else if (str == "Push")
		{
			int val; cin >> val;
			sta.push(val);
		}
	}
	return 0;
}
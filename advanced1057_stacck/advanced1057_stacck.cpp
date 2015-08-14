#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include<vector>
using namespace std;
class BIT
{
private:
	vector<int> Elem;
	int Size;
	int lowbit(int n)
	{
		return n&(-n);
	}
public:
	BIT(int size) :Size(size + 1)  /*想想看还是+1好了，要不申请了100的空间只能用到99感觉太奇怪了*/
	{
		Elem.resize(Size);
	}
	int GetSum(int right)/*[0,right]*/
	{
		int sum = 0;
		while (right)
		{
			sum += Elem[right];
			right -= lowbit(right);
		}
		return sum;
	}
	int GetSum(int left, int right)/*[left,right]*/
	{
		return GetSum(left - 1) - GetSum(right);
	}
	void Add(int value, int index)
	{
		while (index < Size)
		{
			Elem[index] += value;
			index += lowbit(index);
		}
	}
	~BIT()
	{
	}
};
BIT bit(100000);
int getmid(int size)
{
	int index = (size + 1) / 2;
	int left = 1, right = 100000, mid;
	while (left<right)
	{
		mid = (left + right) / 2;
		if (bit.GetSum(mid)<index)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}
int main()
{
	int n, tmp;
	scanf("%d", &n);
	stack<int> s;
	char str[10];
	while (n--)
	{
		scanf("%s", str);
		switch (str[1])
		{
		case 'e':
		{
					if (s.empty())
						printf("Invalid\n");
					else
						printf("%d\n", getmid(s.size()));
					break;
		}
		case 'o':
		{
					if (s.empty())
						printf("Invalid\n");
					else
					{
						tmp = s.top(); s.pop();
						printf("%d\n", tmp);
						bit.Add(-1, tmp);
					}
					break;
		}
		case 'u':
		{
					scanf("%d", &tmp); s.push(tmp);
					bit.Add(1, tmp);
		}
			break;
		}
	}
	return 0;
}
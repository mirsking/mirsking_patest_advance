#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	int N, M;
	cin >> N >> M;
	vector<int> coins;
	for (int i = 0; i < N;i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp < M)
			coins.push_back(tmp);
	}
	N = coins.size();
	if (N == 1)
	{
		cout << "No Solution" << endl;
		return 0;
	}
	sort(coins.begin(), coins.end());

	int left = 0; int right = coins.size() - 1;
	int sum = coins[left] + coins[right];
	while (1)
	{
		while (sum > M)
		{
			right--;
			if (left>=right)
			{
				cout << "No Solution" << endl;
				return 0;
			}
			sum = coins[left] + coins[right];
		}
		if (sum == M)
		{
			cout << coins[left] << " " << coins[right] << endl;
			return 0;
		}
		while (sum < M)
		{
			left++;
			if (left >= right)
			{
				cout << "No Solution" << endl;
				return 0;
			}
			sum = coins[left] + coins[right];
			while (sum < M)
			{
				right++;
				if (right == N)
				{
					right = N-1;
					break;
				}
				sum = coins[left] + coins[right];
			}
			if (sum == M)
			{
				cout << coins[left] << " " << coins[right] << endl;
				return 0;
			}
		}
	}
	return 0;

}
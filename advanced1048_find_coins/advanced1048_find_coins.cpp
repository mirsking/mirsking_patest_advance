#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	int N, M;
	cin >> N >> M;
	vector<int> coins(N);
	for (int i = 0; i < N;i++)
	{
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());

	int left = 0; int right = coins.size() - 1;
	int sum = coins[left] + coins[right];
	bool find_flag = false;
	while (!find_flag)
	{
		while (sum > M)
		{
			right--;
			if (right == left)
			{
				right--;
				break;
			}
			sum = coins[left] + coins[right];
		}
		if (sum == M)
		{
			cout << coins[left] << " " << coins[right] << endl;
			find_flag = true;
			break;
		}
		while (sum < M)
		{
			left++;
			if (left == right)
				break;
			sum = coins[left] + coins[right];
			while (sum < M)
			{
				right++;
				if (right == N)
				{
					right--;
					break;
				}
				sum = coins[left] + coins[right];
			}
			if (sum == M)
			{
				cout << coins[left] << " " << coins[right] << endl;
				find_flag = true;
				break;
			}
		}
		if (right <= left)
		{
			cout << "No Solution" << endl;
			find_flag = true;
			break;
		}
	}
	return 0;

}
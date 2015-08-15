#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
** dp problem, 01 package problem
** L(i,j) 表示前i号硬币中选择，总价值小于等于j的序列的最大面值和
L(i,j) = 
0,										i==0 || j==0;
L(i-1,j),								coins[i] > j;
max{L(i-1,j),  L(i-1, j-a[i])+a[i]},	coins[i] <= j;
*/

void dp_solve(vector<int>& coins, int M, int N)
{
	vector<vector<int>> dp;
	dp.resize(M + 1);
	for (int i = 0; i <= M; i++)
		dp[i].resize(N + 1);

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (coins[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j],
								dp[i - 1][j - coins[i]] + coins[i]);
		}
	}

	if (dp[M][N] != N)
	{
		cout << "No Solution" << endl;
		return;
	}
	
	//回溯
	int i = M, j = N;
	while (j > 0)
	{
		if (dp[i][j] == dp[i - 1][j - coins[i]] + coins[i])
		{
			cout << coins[i];
			j -= coins[i];
			if (j != 0)
				cout << " ";
		}

		i--;
	}

}

int main()
{
	int M, N;
	vector<int> coins;
	cin >> M >> N;
	coins.push_back(0);
	for (int i = 0; i < M;i++)
	{
		int tmp; cin >> tmp;
		coins.push_back(tmp);
	}
	sort(coins.rbegin(), coins.rend()-1);
	dp_solve(coins, M, N);
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getTableSize(int N)
{
	if (N == 1 || N == 2)
		return 2;
	else if (N == 3)
		return 3;
	bool prime_flag = true;
	for (int i = 2; i <= (int)sqrt(N); i++)
	{
		if (N%i == 0)
		{
			prime_flag = false;
			break;
		}
	}
	if (prime_flag)
		return N;
	else
		return getTableSize(N + 1);
}

int getInsertPos(int val, vector<int>& hash_table)
{
	int n = hash_table.size();
	int key = val%n;
	if (hash_table[key] == -1)
	{
		hash_table[key] = val;
		return key;
	}
	else
	{
		//Quadratic probing
		int old_key = key;
		for (int i = 1; i < n; i++)
		{
			key = (old_key + i*i)%n;
			if (hash_table[key] == -1)
			{
				hash_table[key] = val;
				return key;
			}
		}
		return -1;
	}
}

int main()
{
	int N, m;
	cin >> N >> m;
	int n = getTableSize(N);
	vector<int> hash_table(n, -1);
	for (int i = 0; i < m; i++)
	{
		int val; cin >> val;
		int res = getInsertPos(val, hash_table);
		if (res == -1)
			cout << "-";
		else
			cout << res;
		if (i != m - 1)
			cout << " ";
	}
	return 0;
}
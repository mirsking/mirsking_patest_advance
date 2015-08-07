#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{

	unordered_map<int, int> colors;
	int M, N;
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (colors.find(tmp) != colors.end())
				colors[tmp]++;
			else
				colors[tmp] = 1;
		}
	}
	int max_count = 0, max_color = -1;
	for (auto it = colors.begin(); it != colors.end();it++)
	{
		if (it->second > max_count)
		{
			max_count = it->second;
			max_color = it->first;
		}
	}
	if (max_color != -1)
		cout << max_color;
	return 0;
}
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	vector<pair<int, int>> res;
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> chain(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &chain[i]);
	
	int left = 0, right = -1;
	int sum = 0, min = INT_MAX;
	while (1)
	{
		while (sum < M)// �������Ҷ�����
		{
			right++;
			if (right == N) // ���쵽ĩβ��
				break;

			sum += chain[right];
		}
		if (sum >= M)
		{
			if (sum < min)//�����ŷ�������
			{
				min = sum;
				res.clear();
				res.push_back(make_pair(left, right));
			}
			else if (sum == min)
			{
				res.push_back(make_pair(left, right));
			}
		}
		//�������
		while (sum >= M)
		{
			sum -= chain[left];
			left++;
			if (sum >= M)
			{
				if (sum < min)//�����ŷ�������
				{
					min = sum;
					res.clear();
					res.push_back(make_pair(left, right));
				}
				else if (sum == min)
				{
					res.push_back(make_pair(left, right));
				}
			}
		}

		if (right == N)
			break;
	}

	for (auto& c : res)
		printf("%d-%d\n", c.first + 1, c.second + 1);

	return 0;
}
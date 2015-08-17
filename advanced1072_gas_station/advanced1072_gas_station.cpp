#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
using namespace std;

void calDist(const vector<vector<int>>& map, int start, vector<int>& distances)
{
	distances = vector<int>(map.size(), INT_MAX);
	vector<bool> visited(map.size(), false);
	queue<int> que;
	que.push(start);
	distances[start] = 0;
	while (!que.empty())
	{
		int start = que.front();
		int curr_dis = distances[start];
		for (int i = 0; i < map.size(); i++)
		{
			if (i != start && map[start][i] != -1)
			{
				if (!visited[i])
					que.push(i);
				if (distances[i] > map[start][i] + curr_dis)
					distances[i] = map[start][i] + curr_dis;
			}
		}

		visited[start] = true;
		que.pop();
	}
}

int main()
{
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	vector<vector<int>> map;
	map.resize(N + M);
	for (auto& m : map)
		m = vector<int>(N+M, -1);

	for (int i = 0; i < K; i++)
	{
		string a, b;
		int aa, bb, d;
		cin >> a >> b >> d;
		if (a[0] == 'G')
			aa = stoi(a.substr(1, a.size() - 1)) + N;
		else
			aa = stoi(a);
		if (b[0] == 'G')
			bb = stoi(b.substr(1, b.size() - 1)) + N;
		else
			bb = stoi(b);

		map[aa-1][bb-1] = d;
		map[bb - 1][aa - 1] = d;
	}

	
	int min_dis = INT_MIN;
	int max_sum = INT_MIN;
	int min_index = -1;
	for (int i = 0; i < M; i++)
	{
		int start = i + N;
		vector<int> distances;
		calDist(map, start, distances);

		bool succ_flag = true;
		int sum = 0, min_i_dist = INT_MAX;
		for (int j = 0; j < N; j++)
		{
			if (distances[j]>D)
			{
				succ_flag = false;
				break;
			}
			if (distances[j] < min_i_dist)
				min_i_dist = distances[j];
			sum += distances[j];
		}
		if (succ_flag)
		{
			if ((min_i_dist > min_dis) ||
				(min_i_dist==min_dis)&& sum < max_sum)
			{
				max_sum = sum;
				min_dis = min_i_dist;
				min_index = i;
			}
		}
	}

	if (min_index != -1)
	{
		printf("G%d\n", min_index + 1);
		printf("%.1f %.1f", (float)min_dis, (float)max_sum / N);
	}
	else
		printf("No Solution");

	return 0;
}
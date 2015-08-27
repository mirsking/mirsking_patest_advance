/*#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<vector<int>> map_t;

void Dijkstra(const map_t& map, int n, vector<int> & distance, int L)
{
	int N = map.size() - 1;

	distance = vector<int>(N+1, INT_MAX); 
	vector<bool> visited(N+1, false);

	distance[n] = 0;
	for (int i = 1; i <= N; i++)
	{
		//1. find the min neighbor
		int min_dis = INT_MAX, min_neighbor = n;
		for (int j = 1; j <=N; j++)
		{
			if (visited[j] == false && distance[j] < min_dis)
			{
				min_dis = distance[j];
				min_neighbor = j; 
			}
		}
		visited[min_neighbor] = true;

		//2. update the distance
		for (int j = 1; j <= N; j++)
		{
			if (j != i && !visited[j] && map[min_neighbor][j]!=0)
			{
				if (distance[j] > distance[min_neighbor] + 1)
					distance[j] = distance[min_neighbor] + 1;
			}
		}
	}
}

int getForwards(const map_t& map, int L, int n)
{
	vector<int> dist;
	Dijkstra(map, n, dist, L);
	int count = 0;
	for (int i = 1; i < dist.size(); i++)
	{
		if (i != n && dist[i] <= L)
			count++;
	}
	return count;
}


int main()
{
	int N, L;
	cin >> N >> L;

	vector<vector<int>> map;
	map.resize(N+1);
	for (auto& m : map)
		m.resize(N+1);

	for (int i = 1; i <= N; i++)
	{
		int n; cin >> n;
		while (n--)
		{
			int j; cin >> j;
			map[j][i] = 1;
		}
	}

	int NN; cin >> NN;
	while (NN--)
	{
		int n; cin >> n;
		cout << getForwards(map, L, n) << endl;
	}
	return 0;
}*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main()
{
	//改用邻接表储存
	vector<vector<int>> map;
	int N, L;
	cin >> N >> L;
	map.resize(N);
	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		for (int j = 0; j < n; j++)
		{
			int tmp; cin >> tmp;
			map[tmp - 1].push_back(i);
		}
	}

	int NN; cin >> NN;
	while (NN--)
	{
		int begin; cin >> begin;
		begin = begin - 1;
		deque<int> que;
		que.push_back(begin);

		int cur_level = 0;
		int level_back = que.back();
		//vector<int> levels(N, -1);
		//levels[begin] = 0;
		vector<bool> visited(N, false);
		visited[begin] = true;
		while (!que.empty())
		{
			int front = que.front();
			que.pop_front();
			for (int j = 0; j < map[front].size(); j++)
			{
				if (!visited[map[front][j]])
				{
					que.push_back(map[front][j]);
					visited[map[front][j]] = true;
				}
			}
			if (front == level_back)
			{
				level_back = que.back();
				cur_level++;
			}

			if (cur_level >= L)
				break;
		}
		int count = 0;
		for (auto it = visited.begin(); it != visited.end(); it++)
		{
			if (*it==true)
				count++;
		}
		cout << count-1 << endl;
	}

	
	return 0;
}
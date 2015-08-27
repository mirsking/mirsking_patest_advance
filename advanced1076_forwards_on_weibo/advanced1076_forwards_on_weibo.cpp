#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<vector<int>> map_t;

void Dijkstra(const map_t& map, int n, vector<int> & distance)
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
	Dijkstra(map, n, dist);
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
}
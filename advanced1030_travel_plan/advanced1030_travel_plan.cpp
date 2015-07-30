#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct Highway
{
	int start, end;
	int distance;
	int cost;
};
struct City {
	vector<vector<Highway>> map;
	int N;
	int V;
};

/** 
* find a shortest path from a to b
*/
void Dijkstra(const City& city, const int a, const int b, vector<int>&path, int& sum_dist, int& sum_cost)
{
	vector<bool> visited(city.N, false);// 是否被访问标志
	vector<int> dist(city.N, INT_MAX);
	vector<int> cost(city.N, INT_MAX);
	vector<int> parent(city.N, a);
	vector<vector<int>> paths;
	dist[a] = 0;
	cost[a] = 0;
	parent[a] = -1;
	
	for (int count = 0; count < city.N; count++)
	{
		// find the min neighbor
		int min = INT_MAX, u = 0;
		for (int i = 0; i < city.N; i++)
		{
			if (visited[i] == false && dist[i] <= min)
				min = dist[i], u = i;
		}
		
		visited[u] = true;
		for (int v = 0; v < city.N; v++)
		{
			if (!visited[v] && city.map[u][v].distance>0 && dist[u] != INT_MAX)
			{
				if (dist[u] + city.map[u][v].distance < dist[v])
				{
					dist[v] = dist[u] + city.map[u][v].distance;
					cost[v] = cost[u] + city.map[u][v].cost;
					parent[v] = u;
				}
				else if (dist[u] + city.map[u][v].distance == dist[v])
				{
					if (cost[u] + city.map[u][v].cost < cost[v])
					{
						dist[v] = dist[u] + city.map[u][v].distance;
						cost[v] = cost[u] + city.map[u][v].cost;
						parent[v] = u;
					}
				}
			}
		}
	}
	sum_dist = dist[b];
	sum_cost = cost[b];
	int end = b;
	path.insert(path.begin(), end);
	while (parent[end] != -1)
	{
		path.insert(path.begin(), parent[end]);
		end = parent[end];
	}

}

int main()
{
	City city;
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	city.N = N;
	city.V = M;
	auto& map = city.map;
	map.resize(N);
	for (int i = 0; i < city.N; i++)
	{
		map[i].resize(N);
	}
	for (int i = 0; i < city.V; i++)
	{
		Highway highway;
		scanf("%d %d %d %d", &highway.start, &highway.end, &highway.distance, &highway.cost);
		map[highway.start][highway.end].distance = highway.distance;
		map[highway.end][highway.start].distance = highway.distance;
		map[highway.start][highway.end].cost = highway.cost;
		map[highway.end][highway.start].cost = highway.cost;
	}

	vector<int> path;
	int sum_path = 0;
	int cost = 0;
	Dijkstra(city, S, D, path, sum_path, cost);
	for (auto& n : path)
		printf("%d ", n);
	printf("%d %d", sum_path, cost);

	return 0;
}
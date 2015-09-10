#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<int>>& graph, int start, int end, vector<int>& dist, vector<vector<int>>& paths)
{
	int n = graph.size();
	vector<bool> visited(n, false);
	dist = vector<int>(n, INT_MAX);
	
	//distance from start is 0;
	dist[start] = 0;

	// all vertex
	for (int count = 0; count < n; count++)
	{
		//find the vertex with min dist
		int min_dist = INT_MAX; 
		int u; // min index
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false && dist[i] < min_dist)
			{
				min_dist = dist[i];
				u = i;
			}
		}

		// update the picked vertex's visted flag to be true
		visited[u] = true;

		//update the dist value of adjacent vertices of the picked vertex
		for (int v = 0; v < n; v++)
		{
			if (visited[v] == false && graph[u][v]>0 && dist[u] != INT_MAX)
			{

				if (dist[u] + graph[u][v] < dist[v])
				{
					paths[v].clear();
					paths[v].push_back(u);
					dist[v] = dist[u] + graph[u][v];
				}
				else if (dist[u] + graph[u][v] == dist[v])
				{
					paths[v].push_back(u);
				}
			}
		}
		
	}
}

struct RESULT{
	int path_num;
	int min_city_num;
	int max_happy;
	vector<int> path;

	int happy;
	int city_num;
	vector<int> possible_path;

	RESULT() :path_num(0), min_city_num(0), max_happy(0), happy(0), city_num(0)
	{
		path.clear(); 
		possible_path.clear();
	}
};

void dfs(const vector<vector<int>>& paths, int start,
	int curr,
	const vector<int>& happiness,
	RESULT&  res
	)
{
	res.possible_path.push_back(curr);
	res.city_num++;
	res.happy += happiness[curr];
	if (curr == start)
	{
		res.path_num++;
		if (res.happy > res.max_happy)
		{
			res.max_happy = res.happy;
			res.path = res.possible_path;
			res.min_city_num = res.city_num;
		}
	}
	else
	{
		for (int i = 0; i < paths[curr].size(); i++)
		{
			dfs(paths, start, paths[curr][i], happiness, res);
		}
	}


	res.possible_path.pop_back();
	res.city_num--;
	res.happy -= happiness[curr];
	return;
}


int main()
{
	map<int, string> int2str;
	map<string, int > str2int;
	
	int n, k; string start;
	cin >> n >> k >> start;
	vector<int> happiness(n, 0);
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++)
		graph[i].resize(n);

	str2int[start] = 0;
	int2str[0] = start;
	happiness[0] = 0;

	string tmp;
	for (int i = 1; i < n; i++)
	{
		int ha;
		cin >> tmp >> ha;
		str2int[tmp] = i;
		int2str[i] = tmp;
		happiness[i] = ha;
	}

	for (int i = 0; i < k; i++)
	{
		string ca, cb;
		int dist;
		cin >> ca >> cb >> dist;
		int a, b;
		a = str2int[ca];
		b = str2int[cb];
		graph[a][b] = dist;
		graph[b][a] = dist;
	}

	vector<int> dist;
	vector<vector<int>> paths(n);
	dijkstra(graph, str2int[start], str2int["ROM"], dist, paths);
	RESULT res;
	dfs(paths, str2int[start], str2int["ROM"], happiness, res);

	res.min_city_num -= 1;//minius the start city
	int ave = res.max_happy / res.min_city_num;
	cout << res.path_num << " ";
	cout << dist[str2int["ROM"]]<< " ";
	cout << res.max_happy << " ";
	cout << ave << endl;

	for (auto it = res.path.rbegin(); it != res.path.rend(); it++)
	{
		cout << int2str[*it];
		if (it != res.path.rend() - 1)
			cout << "->";
	}
	return 0;
}
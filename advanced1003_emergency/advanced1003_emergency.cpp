#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<int>>& mp, int start, vector<int>& dists, vector<vector<int>>& paths)
{
	int n = mp.size();
	dists = vector<int>(n, INT_MAX);
	paths.resize(n);
	vector<bool> visited(n, false);

	dists[start] = 0;

	for (int count = 0; count < n; count++)
	{
		//find min start
		int min_dist = INT_MAX;
		int u = start;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false && dists[i] < min_dist)
			{
				min_dist = dists[i];
				u = i;
			}
		}

		visited[u] = true;
		//update the dists
		for (int v = 0; v < n; v++)
		{
			if (visited[v] == false && mp[u][v]>0 && dists[u] != INT_MAX)
			{
				if (dists[u] + mp[u][v] < dists[v])
				{
					dists[v] = dists[u] + mp[u][v];
					paths[v].clear();
					paths[v].push_back(u);
				}
				else if (dists[u] + mp[u][v] == dists[v])
				{
					paths[v].push_back(u);
				}
			}
		}
	}
}


void dfs(const vector<vector<int>>& paths,int start, int end, int& path_count, const vector<int>& hands, int& cur_hands, int& max_hands)
{
	cur_hands += hands[end];
	if (end == start)
	{
		path_count++;
		if (max_hands < cur_hands)
		{
			max_hands = cur_hands;
		}
	}
	else
	{
		for (auto e : paths[end])
		{
			dfs(paths, start, e, path_count, hands, cur_hands, max_hands);
		}
	}
	cur_hands -= hands[end];
}

int main()
{
	int n, k, start, end;
	cin >> n >> k >> start >> end;
	vector<int> hands(n);
	for (int i = 0; i < n; i++)
	{
		cin >> hands[i];
	}

	vector<vector<int>> mp(n);
	for (int i = 0; i < n; i++)
		mp[i].resize(n);
	for (int i = 0; i < k; i++)
	{
		int a, b, dis;
		cin >> a >> b >> dis;
		mp[a][b] = dis;
		mp[b][a] = dis;
	}

	vector<int> dists;
	vector<vector<int>> paths;
	dijkstra(mp, start, dists, paths);

	int path_count = 0;
	int curr_hand = 0, max_hand = 0;
	dfs(paths, start, end, path_count, hands, curr_hand, max_hand);

	cout << path_count << " " << max_hand;

	return 0;

}
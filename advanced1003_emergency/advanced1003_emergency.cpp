#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct map_properity{
	int color;
	int distance;
	int resouce;
	map_properity():
		color(-1),distance(0),resouce(0){};
};

struct emergency_map{
	int N;// number of cities
	int M;// number of roads
	int begin, end;
	vector<int> teams_vec;
	vector<vector<int> > city_map;
	vector<map_properity> city_map_properity;
};


int main(int argc, char** argv)
{
	emergency_map e_map;
	cin >> e_map.N >> e_map.M >> e_map.begin >> e_map.end;
	int tmp;
	for (int i = 0; i < e_map.N; i++)
	{
		cin >> tmp;
		e_map.teams_vec.push_back(tmp);
	}

	e_map.city_map.resize(e_map.N);
	for (auto& vec : e_map.city_map)
		vec.resize(e_map.N);
	e_map.city_map_properity.resize(e_map.N);

	for (int i = 0; i < e_map.M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		e_map.city_map[a][b] = c;
	}


	

	return 0;
}
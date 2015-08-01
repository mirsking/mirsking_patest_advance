#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct GasStation{
	double price;
	double distancce;
};

bool closer(const GasStation& lhs, const GasStation& rhs)
{
	return lhs.distancce < rhs.distancce;
}
/**
* return true: find cheaper station than current in next_index
* return false, next_index != -1: no cheaper station, find cheapest station in next_index
* return false, next_index == -1: no station
*/
bool findMin(vector<GasStation>& stations, int cur_index, double max_reachable_distance, int& next_index)
{
	auto& curr_sta = stations[cur_index];
	max_reachable_distance += curr_sta.distancce;
	int cheaper_index=-1, cheapest_index=-1;
	double cheapest_price = 1000000.0;
	for (size_t i = cur_index+1; i < stations.size(); i++)
	{
		auto& next_sta = stations[i];
		if (next_sta.distancce <= max_reachable_distance)//可以到达的最远距离
		{
			if (next_sta.price < curr_sta.price) // 找到cheaper的station
			{
				cheaper_index = i;
			}
			else if (next_sta.price < cheapest_price)
			{
				cheapest_price = next_sta.price;
				cheapest_index = i;
			}
		}
		else
			break;
	}
	if (cheaper_index != -1)
	{
		next_index = cheaper_index;
		return true;
	}
	else if (cheapest_index != -1)
	{
		next_index = cheapest_index;
		return false;
	}
	else
	{
		next_index = -1;
		return false;
	}

}

int main()
{
	vector<GasStation> stations;
	double C, D, unit_gas;
	int N;

	cin >> C >> D >> unit_gas >> N;
	while (N--)
	{
		GasStation sta;
		cin >> sta.price >> sta.distancce;
		stations.push_back(sta);
	}
	sort(stations.begin(), stations.end(), closer);

	double sum_cost = 0;
	double max_distance = 0;
	double max_steps = C*unit_gas;
	double remain_gas = 0;


	return 0;
}
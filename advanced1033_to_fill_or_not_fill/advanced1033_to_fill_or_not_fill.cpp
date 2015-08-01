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
				break;
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

	// start point is destination
	if (D == 0)
	{
		printf("%.2lf", 0.0);
		return 0;
	}
	// start point has no station
	if (stations[0].distancce > 0)
	{
		printf("The maximum travel distance = %.2lf", 0.0);
		return 0;
	}

	double sum_cost = 0;
	double sum_distance = 0;
	double max_steps = C*unit_gas;
	double remain_gas = 0;
	bool to_end = false;

	int curr_index = 0;
	bool return_flag = false;
	while (!return_flag)
	{
		auto& curr_st = stations[curr_index];
		int next_index;
		if (findMin(stations, curr_index, max_steps, next_index))// find cheaper gas station
		{
			auto& next_st = stations[next_index];
			if (next_st.distancce >= D) // next_index is further than destination
			{
				double add_gas = (D - curr_st.distancce) / unit_gas - remain_gas;
				if (add_gas < 0) add_gas = 0;
				sum_cost += add_gas*curr_st.price;
				printf("%.2lf", sum_cost);
				return_flag = true;
				break;
			}
			else // station is before the destination
			{
				double add_gas = (next_st.distancce - curr_st.distancce) / unit_gas - remain_gas;
				if (add_gas < 0) add_gas = 0;
				sum_cost += add_gas*curr_st.price;
				sum_distance = next_st.distancce;
				remain_gas = 0;
			}
			curr_index = next_index;
		}
		else
		{
			if (next_index != -1)//find the cheapest gas
			{
				auto& next_st = stations[next_index];
				if (next_st.distancce >= D) // next_index is further than destination
				{
					double add_gas = (D - curr_st.distancce) / unit_gas - remain_gas;
					if (add_gas < 0) add_gas = 0;
					sum_cost += add_gas*curr_st.price;
					printf("%.2lf", sum_cost);
					return_flag = true;
					break;
				}
				else
				{
					double add_gas = C-remain_gas;
					if (add_gas < 0) add_gas = 0;
					sum_cost += add_gas* curr_st.price;
					sum_distance = next_st.distancce;
					remain_gas = C - (next_st.distancce - curr_st.distancce) / unit_gas;
				}
				curr_index = next_index;
			}
			else // no gas station
			{
				if (max_steps >= D-curr_st.distancce) // can go from current gas station to the destination
				{
					double add_gas = (D - curr_st.distancce) / unit_gas - remain_gas;
					if (add_gas < 0) add_gas = 0;
					sum_cost += add_gas*curr_st.price;
					printf("%.2lf", sum_cost);
					return_flag = true;
					break;
				}
				else
				{
					sum_distance += max_steps;
					printf("The maximum travel distance = %.2lf", sum_distance);
					return_flag = true;
					break;
				}
			}
		}
	}
	return 0;
}
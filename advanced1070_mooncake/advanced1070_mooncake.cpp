#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Mooncake {
	float num;
	float price;
	bool operator < (const Mooncake& rhs) const
	{
		return price < rhs.price;
	}
};

int main()
{
	int N; float d;
	cin >> N >> d;
	vector<Mooncake> cakes;
	for (int i = 0; i < N;i++)
	{
		Mooncake cake;
		cin >> cake.num;
		cakes.push_back(cake);
	}
	for (int i = 0; i < N; i++)
	{
		float tmp;
		cin >> tmp;
		cakes[i].price = tmp / cakes[i].num;
	}
	sort(cakes.rbegin(), cakes.rend());
	int sum = 0;
	float profit = 0;
	for (int i = 0; i < N; i++)
	{
		if (d - sum >= cakes[i].num)
		{
			sum += cakes[i].num;
			profit += cakes[i].price*cakes[i].num;
		}
		else
		{
			profit += cakes[i].price* (d - sum);
			sum = d;
			break;
		}
	}
	printf("%.2f", profit);
	return 0;
}
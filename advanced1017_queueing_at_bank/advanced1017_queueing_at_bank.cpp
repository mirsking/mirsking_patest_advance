#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

typedef long long LL;

class Customer{
public:
	double arrive_time;
	double process_time;
	double wait_time;

};

bool arriverEarlier(const Customer& lhs, const Customer& rhs)
{
	return lhs.arrive_time < rhs.arrive_time;
}

bool queuePriority(const Customer& lhs, const Customer& rhs)
{
	return lhs.process_time < rhs.process_time;
}

bool operator> (const Customer& lhs, const Customer& rhs)
{
	return lhs.process_time > rhs.process_time;
}

const double BEGIN_TIME = 8 * 60;
const double END_TIME = 17 * 60;
const double MAX_DELTER_TIME = END_TIME - BEGIN_TIME;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<Customer> customers;
	for (int i = 0; i < N; i++)
	{
		Customer customer;
		int hh, mm, ss;
		scanf("%d:%d:%d %lf", &hh, &mm, &ss, &customer.process_time);
		customer.arrive_time = (hh * 60 + mm) + (double)ss/60 - BEGIN_TIME;
		customer.wait_time = 0.0;
		if (customer.arrive_time<=MAX_DELTER_TIME)
			customers.push_back(customer);
	}

	sort(customers.begin(), customers.end(), arriverEarlier);

	priority_queue<Customer, vector<Customer>, greater<Customer> > que;
	for (int i = 0; i < customers.size(); i++)
	{
		auto& cus = customers[i];
		if (que.size() < K)
		{
			if (cus.arrive_time < 0)
				cus.wait_time = abs(cus.arrive_time);
			que.push(cus);
		}
		else
		{
			Customer cus_k = que.top();
			cus.wait_time = cus_k.process_time - cus.arrive_time;
			cus.wait_time = cus.wait_time < 0 ? 0 : cus.wait_time;
			que.pop();
			cus.process_time += cus_k.process_time;
			que.push(cus);
		}
	}

	double sum_wait_time = 0;
	for (int i = 0; i < customers.size(); i++)
		sum_wait_time += customers[i].wait_time;

	printf("%.1lf", sum_wait_time / customers.size());

	return 0;
}
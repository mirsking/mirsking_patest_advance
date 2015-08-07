#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct People{
	string name;
	int age;
	int val;
	bool operator<(const People& peo) const
	{
		if (val != peo.val)
			return val < peo.val;
		else
		{
			if (age != peo.age)
				return age > peo.age;
			else
				return name > peo.name;
		}
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	vector<People> list;
	for (int i = 0; i < N; i++)
	{
		People peo;
		cin >> peo.name >> peo.age >> peo.val;
		list.push_back(peo);
	}
	sort(list.rbegin(), list.rend());

	for (int i = 0; i < K; i++)
	{
		int n, age1, age2;
		cin >> n >> age1 >> age2;

		cout << "Case #" << i + 1 <<":"<< endl;
		int count = 0;
		for (auto& peo : list)
		{
			if (age1 <= peo.age && peo.age <= age2)
			{
				cout << peo.name << " " << peo.age << " " << peo.val << endl;
				count++;
				if (count >= n)
					break;
			}
		}
		if (count == 0)
			cout << "None" << endl;

	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct School{
	int quota_max;
	int last_rank;
	vector<int> admissions;
};

struct Student{
	int id;
	int rank;
	int ge;
	int gi;
	int sum;
	vector<int> apps;
	bool operator < (const Student& rhs) const
	{
		if (sum != rhs.sum)
			return sum < rhs.sum;
		else
		{
			if (ge != rhs.ge)
				return ge < rhs.ge;
			else
				return id < rhs.id;
		}
	}
};

int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	vector<School> schools;
	schools.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> schools[i].quota_max;
		schools[i].last_rank = -1;
	}
	vector<Student> stus;
	for (int i = 0; i < n;i++)
	{
		Student stu;
		stu.id = i;
		cin >> stu.ge >> stu.gi;
		stu.sum = stu.ge + stu.gi;
		stu.apps.resize(t);
		for (int i = 0; i < t; i++)
			cin >> stu.apps[i];
		stus.push_back(stu);
	}
	sort(stus.rbegin(), stus.rend());

	int rank = 0;
	Student last_stu = stus[0];
	for (int i = 0; i < stus.size();i++)
	{
		auto& stu = stus[i];
		// update rank
		if (!(stu.ge == last_stu.ge && stu.sum == last_stu.sum))
			rank = i;
		stu.rank = rank;
		last_stu = stu;

		for (auto& app : stu.apps)
		{
			auto& sch = schools[app];
			if (sch.admissions.size() < sch.quota_max)
			{
				sch.admissions.push_back(stu.id);
				sch.last_rank = stu.rank;
				break;
			}
			else
			{
				if (stu.rank == sch.last_rank)
				{
					sch.admissions.push_back(stu.id);
					sch.last_rank = stu.rank;
					break;
				}
			}
		}
	}


	for (auto& sch : schools)
	{
		sort(sch.admissions.begin(), sch.admissions.end());
		for (auto it = sch.admissions.begin(); it != sch.admissions.end(); it++)
		{
			cout << *it;
			if (it != sch.admissions.end() - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
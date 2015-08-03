#pragma warning(disable:4996)
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

void queryStu(const unordered_multimap<string, int>& stus, const string& stu, vector<int>& course)
{
	course.clear();
	auto its = stus.equal_range(stu);
	for (auto it = its.first; it != its.second;it++)
		course.push_back(it->second);
	sort(course.begin(), course.end());
}

int main()
{
	unordered_multimap<string, int> stus;

	int M, N;
	scanf("%d %d\n", &M, &N);
	while (N--)
	{
		int course, num;
		scanf("%d %d\n", &course, &num);
		while (num--)
		{
			string stu; stu.resize(4);
			scanf("%s ", &stu[0]);
			stus.insert(make_pair(stu, course));
		}
		scanf("\n");
	}
	
	while (M--)
	{
		string stu; stu.resize(4);
		if (M == 0)
			scanf("%s", &stu[0]);
		else
			scanf("%s ", &stu[0]);
		vector<int> courses;
		queryStu(stus, stu, courses);
		printf("%s %d", stu.c_str(), courses.size());
		if (courses.size() != 0)
			printf(" ");
		for (auto it = courses.begin(); it != courses.end(); it++)
		{
			printf("%d", *it);
			if (it + 1 != courses.end())
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}


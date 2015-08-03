#pragma warning(disable:4996)
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

typedef unordered_set<string> course_t;

void queryStu(const vector<course_t>& courses, const string& stu, vector<int>& res)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i].find(stu) != courses[i].end())
			res.push_back(i + 1);
	}
}

int main()
{
	vector<course_t> courses;
	int M, N;
	scanf("%d %d\n", &M, &N);
	courses.resize(N);
	while (N--)
	{
		int course, num;
		scanf("%d %d\n", &course, &num);
		while (num--)
		{
			string stu; stu.resize(4);
			scanf("%s ", &stu[0]);
			courses[course - 1].insert(stu);
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
		vector<int> res;
		queryStu(courses, stu, res);
		printf("%s %d", stu.c_str(), res.size());
		if (res.size() != 0)
			printf(" ");
		for (auto it = res.begin(); it != res.end(); it++)
		{
			printf("%d", *it);
			if (it + 1 != res.end())
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}


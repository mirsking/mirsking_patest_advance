#pragma warning(disable:4996)
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <functional>
using namespace std;
typedef unordered_map<int, priority_queue<int, vector<int>, greater<int>>> stu_courses_t;

int main()
{
	stu_courses_t stu_courses;
	int M, N;
	scanf("%d %d\n", &M, &N);
	while (N--)
	{
		int course, num;
		scanf("%d %d\n", &course, &num);
		while (num--)
		{
			char stu[4];
			scanf("%s ", stu);
			int stu_i = (stu[0]-'A') * 26 * 26 * 10 + (stu[1]-'A') * 26 * 10 + (stu[2]-'A') * 10 + stu[3]-'0';
			auto it = stu_courses.find(stu_i);
			if (it == stu_courses.end())
			{	
				priority_queue<int, vector<int>, greater<int>> tmp;
				tmp.push(course);
				stu_courses[stu_i] = tmp;
			}
			else
			{
				stu_courses[stu_i].push(course);
			}
		}
		scanf("\n");
	}
	
	while (M--)
	{
		char stu[4];
		if (M == 0)
			scanf("%s", &stu[0]);
		else
			scanf("%s ", stu);
		int stu_i = (stu[0]-'A') * 26 * 26 * 10 + (stu[1]-'A') * 26 * 10 + (stu[2]-'A') * 10 + stu[3]-'0';
		priority_queue<int, vector<int>, greater<int>> courses = stu_courses[stu_i];
		printf("%s %d", stu, courses.size());
		if (courses.size() != 0)
			printf(" ");
		int count = 0;
		int max = courses.size();
		while (!courses.empty())
		{
			count++;
			printf("%d", courses.top());
			courses.pop();
			if (count !=max) 
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
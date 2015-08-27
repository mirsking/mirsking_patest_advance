#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


struct Student{
	string name;
	string ID;
	int grade;
	const bool operator < (const Student& stu)const
	{
		return grade < stu.grade;
	}
};

int main()
{

	int N;
	cin >> N;
	set<Student> stus;
	for (int i = 0; i < N; i++)
	{
		Student stu;
		cin >> stu.name >> stu.ID >> stu.grade;
		stus.insert(stu);
	}
	int low, high;
	cin >> low >> high;
	int count = 0;
	for (auto it = stus.rbegin(); it != stus.rend(); it++)
	{
		if (it->grade >= low && it->grade <= high)
		{
			cout << it->name << " " << it->ID << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "NONE";

	return 0;
	

}

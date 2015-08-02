#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Student{
	string name;
	string gender;
	string ID;
	int grade;
};

bool compare(const Student& lhs, const Student& rhs)
{
	if (lhs.gender < rhs.gender) // lhs:F
		return false;
	else if (lhs.gender > rhs.gender) // rhs: F
		return true;
	else
	{
		return lhs.grade < rhs.grade;
	}
}

int main()
{
	int N; cin >> N;
	vector<Student> stus;
	while (N--)
	{
		Student stu;
		cin >> stu.name >> stu.gender >> stu.ID >> stu.grade;
		stus.push_back(stu);
	}
	sort(stus.begin(), stus.end(), compare);
	auto& high_stu = *(stus.rbegin());
	auto& low_stu = *(stus.begin());
	if (high_stu.gender == "F")
		cout << high_stu.name << " " << high_stu.ID << endl;
	else
		cout << "Absent" << endl;
	if (low_stu.gender == "M")
		cout << low_stu.name << " " << low_stu.ID << endl;
	else
		cout << "Absent" << endl;
	if (high_stu.gender != low_stu.gender)
		cout << high_stu.grade - low_stu.grade << endl;
	else
		cout << "NA" << endl;

	return 0;

}
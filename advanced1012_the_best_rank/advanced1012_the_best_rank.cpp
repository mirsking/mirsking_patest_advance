#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Student{
	string ID;
	int C, M, E, A;
};

bool sortC(const Student& lhs, const Student& rhs)
{
	return lhs.C > rhs.C;
}
bool sortM(const Student& lhs, const Student& rhs)
{
	return lhs.M > rhs.M;
}
bool sortE(const Student& lhs, const Student& rhs)
{
	return lhs.E > rhs.E;
}
bool sortA(const Student& lhs, const Student& rhs)
{
	return lhs.A > rhs.A;
}

inline int findRank(vector<Student>& stu_v, string ID)
{
	for (int i = 0; i < stu_v.size(); i++)
	{
		if (ID == stu_v[i].ID)
			return i;
	}
	return -1;
}

vector<int> findBestRank(vector<Student>& stu_C, vector<Student>& stu_M, vector<Student>& stu_E, vector<Student>& stu_A, string ID)
{
	vector<int> res;
	int AR = findRank(stu_A, ID);
	if (AR == -1)
		return res;
	
	res.resize(2);
	res[0] = AR;
	res[1] = 0; // 0 is A, then C M E

	int CR = findRank(stu_C, ID);
	if (CR < res[0])
	{
		res[0] = CR;
		res[1] = 1;
	}
	
	int MR = findRank(stu_M, ID);
	if (MR < res[0])
	{
		res[0] = MR;
		res[1] = 2;
	}

	int ER = findRank(stu_E, ID);
	if (ER < res[0])
	{
		res[0] = ER;
		res[1] = 3;
	}

	res[0] += 1;
	return res;

}

int main()
{
	vector<Student> stu_v;;
	char rmap[] = { 'A', 'C', 'M', 'E' };

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		Student stu;
		cin >> stu.ID >> stu.C >> stu.M >> stu.E;
		stu.A = (stu.C + stu.M + stu.E) / 3;		
		stu_v.push_back(stu);
	}

	sort(stu_v.begin(), stu_v.end(), sortC);
	vector<Student> stu_C = stu_v;
	
	sort(stu_v.begin(), stu_v.end(), sortE);
	vector<Student> stu_E = stu_v;

	sort(stu_v.begin(), stu_v.end(), sortM);
	vector<Student> stu_M = stu_v;

	sort(stu_v.begin(), stu_v.end(), sortA);
	vector<Student> stu_A = stu_v;

	for (int i = 0; i < M; i++)
	{
		string ID;
		cin >> ID;
		vector<int> res = findBestRank(stu_C, stu_M, stu_E, stu_A, ID);
		if (res.size() == 0)
			cout << "N/A" << endl;
		else
			cout << res[0] << ' ' << rmap[res[1]] << endl;
	}


	return 0;
}


/* test point, equal score
5 5
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 80 80 82
310105 82 82 83
310101
310102
310103
310104
310105
*/
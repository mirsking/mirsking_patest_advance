#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record{
	int ID;
	string name;
	int score;
};

bool sortByID(const Record& lhs, const Record& rhs)
{
	return lhs.ID < rhs.ID;
}

bool sortByName(const Record& lhs, const Record& rhs)
{
	if (lhs.name < rhs.name)
		return true;
	else if (lhs.name > rhs.name)
		return false;
	else
	{
		if (lhs.ID < rhs.ID)
			return true;
		else
			return false;
	}
}
bool sortByScore(const Record& lhs, const Record& rhs)
{
	if (lhs.score < rhs.score)
		return true;
	else if (lhs.score > rhs.score)
		return false;
	else
	{
		if (lhs.ID < rhs.ID)
			return true;
		else
			return false;
	}
}
int main()
{
	vector<Record> records;
	int N, C;
	cin >> N >> C;
	while (N--)
	{
		Record record;
		cin >> record.ID >> record.name >> record.score;
		records.push_back(record);
	}

	switch (C)
	{
	case 1:sort(records.begin(), records.end(), sortByID); break;
	case 2:sort(records.begin(), records.end(), sortByName); break;
	case 3:sort(records.begin(), records.end(), sortByScore); break;
	}

	for (auto it = records.begin(); it != records.end(); it++)
	{
		printf("%06d %s %d\n", it->ID, (it->name).c_str(), it->score);
	}
	return 0;
}
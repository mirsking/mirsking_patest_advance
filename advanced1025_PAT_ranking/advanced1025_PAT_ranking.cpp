#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long LL;

struct Record{
	string ID;
	LL score;
	LL rank;
	LL location;
	LL local_rank;

	bool operator <(const Record& re) const
	{
		if (this->score < re.score)
			return true;
		else if (this->score > re.score)
			return false;
		else
		{
			if (this->ID > re.ID)
				return true;
			else
				return false;
		}
	}
};

void updateRank(vector<Record>& records, bool is_global=false)
{
	sort(records.rbegin(), records.rend());
	LL score = INT_MIN;
	LL last_rank=1;
	for (auto it = records.begin(); it != records.end(); it++)
	{
		if (score == it->score)
		{
			if (is_global)
				it->rank = last_rank;
			else
				it->local_rank = last_rank;
		}
		else
		{
			if (is_global)
			{
				it->rank = it - records.begin() + 1;
				last_rank = it->rank;
			}
			else
			{
				it->local_rank = it - records.begin() + 1;
				last_rank = it->local_rank;
			}
			score = it->score;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int areaID = 1;
	vector<Record> sorted_records;
	vector<Record> tmp;
	int sum = 0; // sum of records
	while (N--)
	{
		int k;
		cin >> k;
		sum += k;
		vector<Record> records;
		while (k--)
		{
			Record record;
			cin >> record.ID >> record.score;
			record.location = areaID;
			records.push_back(record);
		}
		updateRank(records);
		areaID++;
		tmp.resize(sum);
		merge(sorted_records.rbegin(), sorted_records.rend(), records.rbegin(), records.rend(), tmp.rbegin());
		sorted_records.resize(sum);
		copy(tmp.rbegin(), tmp.rend(), sorted_records.rbegin());
		//sorted_records.resize(sum);
		//merge(sorted_records.rbegin(), sorted_records.rbegin() + sum - k, records.rbegin(), records.rend(), sorted_records.rbegin());
	}
	updateRank(sorted_records, true);

	cout << sorted_records.size() << endl;
	for (auto it = sorted_records.begin(); it != sorted_records.end(); it++)
		cout << it->ID << " " << it->rank << " " << it->location << " " << it->local_rank << endl;

	return 0;
}
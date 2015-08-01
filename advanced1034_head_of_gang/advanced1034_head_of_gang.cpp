#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long LL;

struct Gang{
	unordered_map<string, LL> persons;
	LL weight;
};

struct BriefGang{
	std::string head;
	LL size;
};

void addToGang(vector<Gang>& gangs, string name1, string name2, LL weight)
{
	bool find_gang = false;
	int name1_gang = -1, name2_gang = -1;
	LL count = 0;
	for (auto& gang : gangs)
	{
		if (gang.persons.find(name1) != gang.persons.end())
		{
			name1_gang = count;
		}
		if (gang.persons.find(name2) != gang.persons.end())
		{
			name2_gang = count;
		}
		count++;
	}
	if (name1_gang != -1 && name2_gang == -1) // find name1 but not name2;
	{
		auto& gang = gangs[name1_gang];
		gang.persons[name1] += weight;
		gang.persons[name2] = weight;
		gang.weight += weight;
	}
	else if (name1_gang == -1 && name2_gang != -1)
	{
		auto& gang = gangs[name2_gang];
		gang.persons[name2] += weight;
		gang.persons[name1] = weight;
		gang.weight += weight;
	}
	else if (name1_gang != -1 && name2_gang != -1)
	{
		if (name1_gang == name2_gang) //find name1 and name2 in same gang
		{
			auto& gang = gangs[name1_gang];
			gang.persons[name1] += weight;
			gang.persons[name2] += weight;
			gang.weight += weight;
		}
		else // find name1 and name2 in different gang
		{
			auto& gang1 = gangs[name1_gang];
			auto& gang2 = gangs[name2_gang];
			gang1.persons[name1] += weight;
			gang2.persons[name2] += weight;
			//merge gang1 and gang2
			for (auto& person : gang2.persons)
				gang1.persons[person.first] = person.second;
			gang1.weight += gang2.weight;
			gang1.weight += weight;
			gangs.erase(gangs.begin() + name2_gang);// erase gang2
		}
	}
	else
	{
		Gang gang;
		gang.persons[name1] = weight;
		gang.persons[name2] = weight;
		gang.weight = weight;
		gangs.push_back(gang);
	}
}

string findHead(Gang& gang)
{
	int max_weight = INT_MIN;
	string res;
	for (auto& person : gang.persons)
	{
		if (person.second > max_weight)
		{
			res = person.first;
			max_weight = person.second;
		}
	}
	return  res;
}

bool bgangCompare(const BriefGang& lhs, const BriefGang& rhs)
{
	return lhs.head < rhs.head;
}

int main()
{
	int N, threshold;
	unordered_map<string, LL> persons;
	vector<Gang> gangs;
	cin >> N >> threshold;
	while (N--)
	{
		string name1, name2; LL weight;
		cin >> name1 >> name2 >> weight;
		addToGang(gangs, name1, name2, weight);
	}
	vector<BriefGang> bgangs;
	for (auto& gang : gangs)
	{
		if (gang.persons.size() > 2 && gang.weight > threshold)
		{
			BriefGang bgang;
			bgang.head = findHead(gang);
			bgang.size = gang.persons.size();
			bgangs.push_back(bgang);
		}
	}
	if (bgangs.size() == 0)
		cout << 0;
	else
	{
		sort(bgangs.begin(), bgangs.end(), bgangCompare);
		cout << bgangs.size() << endl;
		for (auto& bgang : bgangs)
		{
			cout << bgang.head << " " << bgang.size << endl;
		}
	}
	
	return 0;
}
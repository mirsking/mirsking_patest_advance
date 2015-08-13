#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
	int ID;
	int talent;
	int virtue;
	const bool operator < (const Person& per) const
	{
		if (talent + virtue != per.talent + per.virtue)
			return talent + virtue < per.talent + per.virtue;
		else
		{
			if (virtue != per.virtue)
				return virtue < per.virtue;
			else
				return ID > per.ID;
		}
	}
};

int L, H;

int main()
{
	int N;
	cin >> N >> L >> H;
	vector<Person> sages, noblemen, foolmen, smallmen;
	while (N--)
	{
		Person per;
		cin >> per.ID >> per.virtue >> per.talent;
		if (per.virtue < L || per.talent < L)
			continue;

		if (per.virtue >= H && per.talent >= H)
			sages.push_back(per);
		else if (per.virtue >= H && per.talent <= H)
			noblemen.push_back(per);
		else if (per.virtue <= H && per.talent <= H && per.virtue >= per.talent)
			foolmen.push_back(per);
		else
			smallmen.push_back(per);
	}

	sort(sages.rbegin(), sages.rend());
	sort(noblemen.rbegin(), noblemen.rend());
	sort(foolmen.rbegin(), foolmen.rend());
	sort(smallmen.rbegin(), smallmen.rend());

	cout << sages.size() + noblemen.size() + foolmen.size() + smallmen.size() << endl;
	for (auto& sa : sages)
		printf("%06d %d %d\n", sa.ID, sa.virtue, sa.talent);
	for (auto& no:noblemen)
		printf("%06d %d %d\n", no.ID, no.virtue, no.talent);
	for (auto& sa : foolmen)
		printf("%06d %d %d\n", sa.ID, sa.virtue, sa.talent);
	for (auto& no : smallmen)
		printf("%06d %d %d\n", no.ID, no.virtue, no.talent);

	return 0;

}
#pragma warning(disable:4996)
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Book{
public:
	string id;
	string title;
	string author;
	string keywords;
	vector<string> v_keywords;
	string publisher;
	string year;
};

class Books{
public:
	unordered_multimap<string, string> m_title,
		m_author, m_keyword, m_publisher, m_year;
};

vector<string> getRes(unordered_multimap<string, string>& dict, string keyword)
{
	vector<string> res;
	auto range = dict.equal_range(keyword);
	if (range.first == range.second)
		cout << "Not Found" << endl;
	else
	{
		for (auto it = range.first; it != range.second; it++)
			res.push_back(it->second);
		sort(res.begin(), res.end());
		for (auto it = res.begin(); it != res.end(); it++)
			cout << *it << endl;
	}

	return res;
}

int main()
{
	int N;
	scanf("%d\n", &N);
	Books dl;
	for (int i = 0; i < N; i++)
	{
		Book bk;
		getline(cin, bk.id);
		getline(cin, bk.title);
		getline(cin, bk.author);
		getline(cin, bk.keywords);
		getline(cin, bk.publisher);
		getline(cin, bk.year);
		dl.m_title.insert(make_pair(bk.title, bk.id));
		dl.m_author.insert(make_pair(bk.author, bk.id));
		dl.m_publisher.insert(make_pair(bk.publisher, bk.id));
		dl.m_year.insert(make_pair(bk.year, bk.id));
		istringstream ss(bk.keywords);
		string tmp;
		while (getline(ss, tmp, ' '))
			dl.m_keyword.insert(make_pair(tmp, bk.id));
	}

	int m;
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		int key;
		scanf("%d: ", &key);
		string word;
		getline(cin, word);
		printf("%d: ", key);
		cout << word << endl;

		switch (key)
		{
			case 1: getRes(dl.m_title, word); break;
			case 2: getRes(dl.m_author, word); break;
			case 3: getRes(dl.m_keyword, word); break;
			case 4: getRes(dl.m_publisher, word); break;
			case 5: getRes(dl.m_year, word); break;
		}
	}
	return 0;
}
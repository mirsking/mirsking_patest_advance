#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef unordered_map<int, string> name_map_t;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	name_map_t name_map;
	vector<vector<int>> courses(M);
	while (N--)
	{
		string name; name.resize(4);
		int n;
		scanf("%s", &name[0]);
		scanf("%d", &n);
		int name_i = (name[0]-'A') * 26 * 26 * 10 + (name[1]-'A') * 26 * 10 + (name[2]-'A') * 10 + name[3]-'0';
		name_map[name_i] = name;
		while (n--)
		{
			int tmp;
			scanf("%d", &tmp);
			courses[tmp-1].push_back(name_i);
		}
	}
	
	for (size_t i = 0; i < courses.size(); i++)
	{
		printf("%d %d\n", i + 1, courses[i].size());
		sort(courses[i].begin(), courses[i].end());
		for (auto& c : courses[i])
			printf("%s\n", name_map[c].c_str());
	}
	return 0;
}
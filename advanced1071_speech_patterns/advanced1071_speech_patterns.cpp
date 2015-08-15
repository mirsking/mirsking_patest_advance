#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	str.push_back('\n');// add a last char to get the last word in the map
	string word;
	map<string, int> words_count;
	for (int i = 0; i < str.size(); i++)
	{
		char& c = str[i];
		if (isalnum(c))
		{
			if (!islower(c))
				c = tolower(c);
			word.push_back(c);
		}
		else
		{
			if (!word.empty())
			{
				if (words_count.find(word) == words_count.end())
					words_count[word] = 1;
				else
					words_count[word] += 1;
				word.clear();
			}
		}
	}

	// find the max count
	int max_count = 0;
	string max_word = "";
	for (auto& word : words_count)
	{
		if (word.second > max_count)// ||
			//(word.second == max_count && word.first < max_word) )
		{
			max_count = word.second;
			max_word = word.first;
		}
	}
	cout << max_word << " " << max_count;


	return 0;
}
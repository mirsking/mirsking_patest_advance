#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NUM = 54;
const int CO = 13;

void changeOrder(vector<string>& cards, vector<int>& shuff)
{
	vector<string> tmp(cards);
	for (size_t i = 0; i < shuff.size(); i++)
		cards[shuff[i]-1] = tmp[i];
}

int main()
{
	int N;
	cin >> N;
	vector<int> shuff;
	shuff.resize(NUM);
	for (int i = 0; i < NUM;i++)
		cin >> shuff[i];
	vector<string> cards;
	string cos[NUM / CO] = { "S", "H", "C", "D" };
	for (int i = 0; i < NUM / CO; i++)
	{
		for (int j = 0; j < CO; j++)
			cards.push_back(cos[i] + to_string(j + 1));
	}
	cards.push_back("J1"); cards.push_back("J2");
	for (int i = 0; i < N; i++)
	{
		changeOrder(cards, shuff);
	}
	for (auto it = cards.begin(); it != cards.end(); it++)
	{
		cout << *it;
		if (it + 1 != cards.end())
			cout << " ";
	}
		
	return 0;

}
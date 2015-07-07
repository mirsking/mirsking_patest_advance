#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

char radix[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

vector<char> convertMarsColor(int r, int g, int b)
{
	vector<char> res;
	res.push_back(radix[r / 13]);
	res.push_back(radix[r % 13]);
	res.push_back(radix[g / 13]);
	res.push_back(radix[g % 13]);
	res.push_back(radix[b / 13]);
	res.push_back(radix[b % 13]);
	return res;
}

int main()
{
	int R, G, B;
	scanf("%d%d%d", &R, &G, &B);
	//cin >> R >> G >> B;
	vector<char> res = convertMarsColor(R, G, B);
	printf("#");
	for (auto it = res.begin(); it != res.end(); it++)
		printf("%c", *it);
	return 0;
}
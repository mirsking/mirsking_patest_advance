#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int a = 0, b = 0;
	int N = str.size();
	if (N == 1)
	{
		printf("%c", str[0]);
		return 0;
	}

	a = (N + 2) / 3;
	b = (N + 2) - 2 * a;

	for (int i = 0; i < a; i++)
	{
		printf("%c", str[i]);
		for (int j = 0; j < b - 2; j++)
		{
			if (i != a - 1)
				printf(" ");
			else
				printf("%c", str[a + j]);
		}
		printf("%c\n", str[N-1-i]);
	}
	return 0;
}
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		bool flag = false;
		LL a, b, c;
		cin >> a >> b >> c;
		LL res = a + b;
		if (a>0 && b > 0 && res <= 0)
			flag = true;
		else if (a < 0 && b < 0 && res >= 0)
			flag = false;
		else
			flag = res>c;

		printf("Case #%d: ", i + 1);
		if (flag == true)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}
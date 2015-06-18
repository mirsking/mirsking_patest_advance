#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int N;
	cin >> N;
	int last, cur=0;
	int sum=0;
	for (int i = 0; i < N; i++)
	{
		last = cur;
		cin >> cur;
		if (cur>last)
			sum += (6*(cur-last) + 5);
		else if (cur < last)
			sum += (4*(last-cur) + 5);
		else
			sum += 5;
	}
	cout << sum;
	return 0;

}
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL getShortestDistance(vector<LL>& distances, LL a, LL b)
{
	a = a - 1; b = b - 1;
	if (a == b)
		return 0;

	LL tmp = a; 
	if (a > b)
	{
		a = b;
		b = tmp;
	}

	// positive direction
	LL sum = 0;
	for (LL i = a; i < b; i++)
		sum += distances[i];
	LL sum2 = 0;
	for (LL i = b; i < distances.size()+a; i++)
	{
		LL tmp = i;
		if (i >= distances.size())
			tmp = i - distances.size();
		sum2 += distances[tmp];
		if (sum2>=sum)
			return sum;
	}
	return sum2;
}

int main()
{
	LL N;
	cin >> N;
	vector<LL> distances;
	while (N--)
	{
		LL tmp; cin >> tmp;
		distances.push_back(tmp);
	}

	LL M;
	cin >> M;
	while (M--)
	{
		LL a, b;
		cin >> a >> b;
		cout << getShortestDistance(distances, a, b) << endl;
	}
	return 0;
}
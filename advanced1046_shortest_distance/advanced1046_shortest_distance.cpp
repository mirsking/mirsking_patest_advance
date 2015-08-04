#include <iostream>
#include <vector>
using namespace std;
#define min(x,y) (x>y?y:x)
typedef long long LL;

LL getShortestDistance(vector<LL>& distances, LL a, LL b)
{
	a = a - 1; b = b - 1;
	if (a == b)
		return 0;

	LL tmp = a; 
	if (a > b)
		a = b, b = tmp;
	LL res = distances[b] - distances[a];
	return min(res, distances[distances.size() - 1] - res);
}

int main()
{
	LL N;
	cin >> N;
	vector<LL> distances;
	distances.resize(N + 1);
	distances[0] = 0;
	for (int i = 1; i <= N;i++)
	{
		LL tmp; cin >> tmp;
		distances[i] = tmp + distances[i - 1];
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
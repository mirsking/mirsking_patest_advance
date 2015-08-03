#include <vector>
#include <iostream>
using namespace std;
#define max(x, y) (x>y?x:y)

int LCS(const vector<int>& X,const vector<int>& Y, vector<vector<int>>& res)
{
	res.resize(X.size()+1);
	for (size_t i = 0; i < res.size(); i++)
		res[i].resize(Y.size() + 1);

	for (size_t i = 0; i < X.size(); i++)
		for (size_t j = 0; j < Y.size(); j++)
			res[i + 1][j + 1] = max(max(res[i][j + 1], res[i + 1][j]), res[i][j]) + (X[i] == Y[j] ? 1 : 0);
	return res[X.size()][Y.size()];

}

int main()
{
	int XX, M, N;
	cin >>XX >> M;
	vector<int> X, Y;
	while (M--)
	{
		int tmp; cin >> tmp;
		X.push_back(tmp);
	}
	cin >> N;
	while (N--)
	{
		int tmp; cin >> tmp;
		Y.push_back(tmp);
	}

	vector<vector<int>> res;
	cout << LCS(X, Y, res);
	return 0;

}
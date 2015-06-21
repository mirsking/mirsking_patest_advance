#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<float> a, b, c;
	a.resize(1001);
	b.resize(1001);
	c.resize(2001);

	int N1, N2;
	cin >> N1;
	for (int i = 0; i < N1; i++)
	{
		int NN; float aa;
		cin >> NN >> aa;
		a[NN] = aa;
	}

	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		int NN; float aa;
		cin >> NN >> aa;
		b[NN] = aa;
	}

	vector<int> expo;
	vector<float> coeff;
	//	for (int i = c.size() - 1; i >= 0; i--)
	//	{
	//		for (int j = 0; j <= i, (i-j)<b.size(); j++)
	//		{
	//			c[i] += a[j] * b[i - j];
	//		}
	//		if (c[i] != 0)
	//		{
	//			expo.push_back(i);
	//			coeff.push_back(c[i]);
	//		}
	//	}

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			c[i + j] += a[i] * b[j];
		}
	}

	for (int i = c.size() - 1; i >= 0; i--)
	{
		if (c[i] != 0)
		{
			expo.push_back(i);
			coeff.push_back(c[i]);
		}
	}

	cout << expo.size();
	for (int i = 0; i < expo.size(); i++)
	{
		printf(" %d %.1f", expo[i], coeff[i]);
	}

	return 0;
}
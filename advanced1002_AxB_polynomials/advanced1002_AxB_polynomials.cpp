#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;
double a[MAX], b[MAX];


int main(int argc, char** argv)
{
	int Na, Nb;
	cin >> Na;
	for (int i = 0; i < Na; i++)
	{
		int aa;
		double bb;
		cin >> aa >> bb;
		a[aa] = bb;
	}

	cin >> Nb;
	for (int i = 0; i < Nb; i++)
	{
		int aa;
		double bb;
		cin >> aa >> bb;
		b[aa] = bb;
	}

	vector<double> output;
	int non_zero_count = 0;
	for (int i = MAX-1; i >=0; i--)
	{
		b[i] += a[i];
		if (b[i] != 0)
		{
			non_zero_count++;
			output.push_back(i);
			output.push_back(b[i]);
		}
	}

	if (output.size() == 0)
		cout << '0' << endl;
	else
	{
		cout << non_zero_count;
		for (int i = 0; i < output.size(); i += 2)
		{
			int tmp = output[i];
			printf(" %d %.1lf", tmp, output[i + 1]);
		}
	}

	return 0;
}
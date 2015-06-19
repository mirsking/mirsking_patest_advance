#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	cin >> N;
	string earlyID, laterID;
	string early_time, later_time;
	for (int i = 0; i < N; i++)
	{
		string ID, sign_in_time, sign_out_time;
		cin >> ID >> sign_in_time >> sign_out_time;
		if (i == 0)
		{
			earlyID = ID;
			early_time = sign_in_time;
			laterID = ID;
			later_time = sign_out_time;
		}
		else
		{
			if (early_time.compare(sign_in_time) > 0)
			{
				earlyID = ID;
				early_time = sign_in_time;
			}

			if (later_time.compare(sign_out_time) < 0)
			{
				laterID = ID;
				later_time = sign_out_time;
			}
		}
	}

	cout << earlyID << ' ' << laterID;
	return 0;

}
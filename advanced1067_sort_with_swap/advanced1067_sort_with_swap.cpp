#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> arr, index;
	index.resize(N);
	for (int i = 0; i < N;i++)
	{
		int tmp; cin >> tmp;
		arr.push_back(tmp);
		index[tmp] = i;
	}
	int count = 0;
	while (1)
	{
		if (index[0] == 0 && is_sorted(arr.begin(), arr.end()))
			break;
		else
		{
			count++;
			int index0, index_swapper;
			index0 = index[0];
			if (index[0] == 0)
			{
				for (int i = 1; i < arr.size(); i++)
				{
					if (arr[i] != i)
					{
						index_swapper = i;
						break;
					}
				}
			}
			else
			{
				index_swapper = index[index0];
			}

			index[0] = index_swapper;
			index[arr[index_swapper]] = index0;
			arr[index0] = arr[index_swapper];
			arr[index_swapper] = 0;
		}


	}
	cout << count;
	return 0;
}
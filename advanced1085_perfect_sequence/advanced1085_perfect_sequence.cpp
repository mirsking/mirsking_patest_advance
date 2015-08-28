#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL N, p;
	cin >> N >> p;
	vector<LL> nums(N);
	for (LL i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	
	// ¶þ·Ö²éÕÒ
	LL left, right, mid;
	LL max_length = 0;
	for (LL i = 0; i < nums.size();i++)
	{
		LL max = nums[i] * p;
		if (max >= *nums.rbegin())
		{
			max_length = (max_length>N - i) ? max_length : N - i;
			break;
		}

		left = i; right = nums.size() - 1;
		while (left < right)
		{
			LL mid = (left + right) / 2;
			if (nums[mid] > max)
				right = mid;
			else if (nums[mid] < max)
				left = mid+1;
			else{
				left = mid + 1; break;
			}
		}

		if (left - i > max_length)
			max_length = left - i;
		
	}

	cout << max_length;
	return 0;
}
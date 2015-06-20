#include <climits>
#include <iostream>
#include <vector>
using namespace std;


int main()
{

    int N;
    vector<int> nums;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int sum = 0;
    int start = 0, end = N - 1;
    int tmp_sum=0, ii=0, jj=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (tmp_sum >= 0)
        {
            tmp_sum += nums[i];
            jj = i;
        }
        else
        {
            tmp_sum = nums[i];
            ii = jj = i;
        }

        if (tmp_sum > sum || (tmp_sum==0 && end==N-1))
        {
            sum = tmp_sum;
            start = ii;
            end = jj;
        }
    }

    cout << sum << ' ' << nums[start] << ' ' << nums[end];
    
    return 0;
}
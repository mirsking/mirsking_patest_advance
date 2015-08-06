#include <iostream>
#include <stack>
using namespace std;


int main()
{
	int M, N, K;
	cin >> M >> N >> K;

	while (K--)
	{
		stack<int> sta;
		int cur = 1;
		int n = N;
		bool possible_flag = true;
		while (n--)
		{
			int tmp; cin >> tmp;
			if (possible_flag)
			{
				while (sta.empty() || sta.top() != tmp)
				{
					sta.push(cur);
					if (sta.size() > M)
					{
						possible_flag = false;
						break;
					}
					cur++;
				}
				if (possible_flag && !sta.empty() && sta.top() == tmp)
					sta.pop();
			}
		}

		if (possible_flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct user{
	string username;
	string password;
};

bool insteadPassword(string& str)
{
	bool res = false;
	for (auto& ch : str)
	{
		if (ch == '1')
		{
			ch = '@';
			res = true;
		}
		else if (ch == '0')
		{
			ch = '%';
			res = true;
		}
		else if (ch == 'l')
		{
			ch = 'L';
			res = true;
		}
		else if (ch == 'O')
		{
			ch = 'o';
			res = true;
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	int N_bak = N;
	if (N == 0)
	{
		printf("There is %d account and no account is modified", N);
		return 0;
	}
	vector<user> changed_users;
	while (N--)
	{
		user u;
		cin >> u.username >> u.password;
		if (insteadPassword(u.password))
			changed_users.push_back(u);
	}

	if (changed_users.size() == 0)
	{
		if (N_bak > 1)
			printf("There are %d accounts and no account is modified", N_bak);
		else
			printf("There is %d account and no account is modified", N_bak);
	}
	else
	{
		printf("%d\n", changed_users.size());
		for (auto& u : changed_users)
		{
			cout << u.username << " " << u.password << endl;
		}
	}
 	return 0;
}
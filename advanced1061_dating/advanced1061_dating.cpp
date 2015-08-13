#include <iostream>
#include <string>
using namespace std;

string DAY[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	string str1, str2, str3, str4;
	cin >> str1;
	cin >> str2;
	cin >> str3;
	cin >> str4;

	bool dayflag = false;
	for (auto it1 = str1.begin(), it2 = str2.begin();
		it1 != str1.end(), it2 != str2.end(); it1++, it2++)
	{
		if (*it1 == *it2)
		{
			if (!dayflag && *it1 >= 'A' && *it1 <= 'G')
			{
				dayflag = true;
				cout << DAY[*it1-'A'] << " ";
			}
			else if (dayflag &&
				((*it1 >= '0'&& *it1 <= '9')
				|| (*it1 >= 'A' && *it1 <= 'N')))
			{
				if (*it1 >= '0' && *it1 <= '9')
					printf("%02d:", *it1 - '0');
				else
					printf("%02d:", *it1 - 'A'+10);
				break;
			}
		}
	}

	int count = 0;
	for (auto it1 = str3.begin(), it2 = str4.begin();
		it1 != str3.end(), it2 != str4.end(); it1++, it2++)
	{
		if (*it1 == *it2)
		{
			if ((*it1 >= 'A' && *it1 <= 'Z') || (*it1 >= 'a' && *it2 <= 'z'))
			{
				printf("%02d", count);
				break;
			}
		}
		count++;
	}
	return 0;
}
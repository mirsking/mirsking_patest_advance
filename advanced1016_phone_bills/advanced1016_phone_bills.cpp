#pragma warning(disable:4996)
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Bill{
public:
	string ID;
	int mo, dd, hh, mm;
	int status; // 0 online, 1 offline
};

class Bills{
public:
	vector<Bill> bills;
	float rate[24];
	float day_price;

	vector<int> getValidBills()
	{
		//trick, get day price
		day_price = 0;
		for (int i = 0; i < 24; i++)
		{
			day_price += rate[i] * 60;
		}

		vector<int> bills_index;
		string id = bills[0].ID;
		bool onlineFlag = false;
		for (int i = 0; i < bills.size(); i++)
		{
			auto& bill = bills[i];
			if (bill.ID == id)
			{
				if (bill.status == 0)
				{
					if (onlineFlag == false)
					{
						bills_index.push_back(i);
						onlineFlag = true;
					}
					else
					{
						bills_index.pop_back();
						bills_index.push_back(i);
					}
				}
				else if (bill.status == 1)
				{
					if (onlineFlag == true)
					{
						bills_index.push_back(i);
						onlineFlag = false;
					}
				}
			}
			else
			{
				if (onlineFlag == true)
					bills_index.pop_back();
				onlineFlag = false;
				id = bills[i].ID;
				i--;
			}
		}

		if (onlineFlag == true)
			bills_index.pop_back();

		return bills_index;
	}

	/*
	void cal2Bills(Bill& bill1, Bill& bill2, int& min, float& price)
	{
		int min1 = (bill1.dd * 24 + bill1.hh) * 60 + bill1.mm;
		int min2 = (bill2.dd * 24 + bill2.hh) * 60 + bill2.mm;
		min = min2 - min1;
		price = 0;

		// day
		int day = min / (24 * 60);
		price += day*day_price;
		min1 %= (24 * 60);
		min2 %= (24 * 60);
		int begin_h = min1 / 60;
		int end_h = min2 / 60;
		for (int i = begin_h; i <end_h; i++)
		{
			int caled_min = (i + 1) * 60 - min1;
			//cout << caled_min << endl;
			price += rate[i] * caled_min;
			min1 += caled_min;
		}
		price += rate[end_h] * (min2 - end_h * 60);

	}
	*/

	float calBill2Begin(Bill& bill)
	{
		float sum = 0;
		int hours = bill.dd * 24 + bill.hh;
		int& mins = bill.mm;
		int i = 0;
		for (; i < hours; i++)
		{
			sum += rate[i % 24] * 60;
		}
		sum += rate[i % 24] * mins;
		return sum;
	}

	void cal2Bills(Bill& bill1, Bill& bill2, int& min, float& price)
	{
		int min1 = (bill1.dd * 24 + bill1.hh) * 60 + bill1.mm;
		int min2 = (bill2.dd * 24 + bill2.hh) * 60 + bill2.mm;
		min = min2 - min1;
		price = calBill2Begin(bill2) - calBill2Begin(bill1);
	}

	void calBills(vector<int>& bills_index)
	{
		if (bills_index.size() == 0 || bills_index.size()%2!=0)
			return;
		string id = "";
		float sum = 0;
		for (int i = 0; i < bills_index.size(); i+=2)
		{
			auto& bill1 = bills[bills_index[i]];
			auto& bill2 = bills[bills_index[i+1]];
			if (id != bill1.ID)
			{
				if (i != 0)// not the first
					printf("Total amount: $%.2f\n", sum);
				printf("%s %02d\n", bill1.ID.c_str(), bill1.mo);
				sum = 0;
				id = bill1.ID;
			}
			int min; float price;
			cal2Bills(bill1, bill2, min, price);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", bill1.dd, bill1.hh, bill1.mm, bill2.dd, bill2.hh, bill2.mm, min, price);
			sum += price;
		}
		printf("Total amount: $%.2f\n", sum);
	}
};

bool lessBill(const Bill& lhs, const Bill& rhs)
{
	if (lhs.ID < rhs.ID)
		return true;
	else if (lhs.ID > rhs.ID)
		return false;
	else
	{
		if (lhs.dd < rhs.dd)
			return true;
		else if (lhs.dd>rhs.dd)
			return false;
		else
		{
			if (lhs.hh < rhs.hh)
				return true;
			else if (lhs.hh > rhs.hh)
				return false;
			else
			{
				if (lhs.mm < rhs.mm)
					return true;
				else if (lhs.mm >= rhs.mm)
					return false;
			}
		}
	}
}


int main()
{
	Bills bs;
	auto& bills = bs.bills;
	for (int i = 0; i < 24; i++)
	{
		int tmp;
		cin >> tmp;
		bs.rate[i] = (float)tmp/100;
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Bill bill;
		cin >> bill.ID;
		scanf(" %d:%d:%d:%d ", &(bill.mo), &(bill.dd), &(bill.hh), &(bill.mm));
		string status;
		cin >> status;
		if (status == "on-line")
			bill.status = 0;
		else
			bill.status = 1;
		bills.push_back(bill);
	}

	sort(bills.begin(), bills.end(), lessBill);
	vector<int> bills_index = bs.getValidBills();
	bs.calBills(bills_index);

	return 0;
}
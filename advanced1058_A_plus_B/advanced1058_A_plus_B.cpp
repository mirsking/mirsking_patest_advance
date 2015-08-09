#pragma warning(disable:4996)
#include <iostream>
using namespace std;

struct Hogwarts{
	int galleon;
	int sickle;//17
	int knut;//29
	static const int KNUT = 29;
	static const int SICKLE = 17;
};

int main()
{
	Hogwarts hog1, hog2, hog3;
	scanf("%d.%d.%d %d.%d.%d", &hog1.galleon, &hog1.sickle, &hog1.knut, 
		&hog2.galleon, &hog2.sickle, &hog2.knut);
	int carry = 0;
	hog3.knut = hog1.knut + hog2.knut;
	carry = hog3.knut / Hogwarts::KNUT;
	hog3.knut = hog3.knut%Hogwarts::KNUT;

	hog3.sickle = hog1.sickle + hog2.sickle + carry;
	carry = hog3.sickle / Hogwarts::SICKLE;
	hog3.sickle = hog3.sickle  % Hogwarts::SICKLE;

	hog3.galleon = hog1.galleon + hog2.galleon + carry;
	printf("%d.%d.%d", hog3.galleon, hog3.sickle, hog3.knut);
	return 0;
}
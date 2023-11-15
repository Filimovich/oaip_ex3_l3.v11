#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	cout.unsetf(ios::floatfield);
	cout << setprecision(50);

	int a;
	int b;
	int c;

	double prec;
	double ad;
	double bd;
	double cd;

	a = 19;
	b = 1;
	c = 1;

	ad = (4.1 - 2.1) / 1;
	bd = 1.2;
	cd = 1.4;

	prec = 0.00000000000001;

	if (fabs(ad - round(ad)) < prec)
		cout << "SUCSESS!" << endl;

	cout << "Result adtrunc: " << trunc(ad) << endl;
	cout << "Result adround: " << round(ad) << endl;
	cout << "Result abs: " << fabs(ad - round(ad)) << endl;

	return (0);
}
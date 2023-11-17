#include <iostream>
#include <cmath>

using namespace std;

double factorial(double arg)
{
	if (arg == 0)
		return (1);

	return (arg * factorial(arg - 1));
}

int main()
{
	double a;

	a = -4;

	cout << factorial(a);

	return (0);
}
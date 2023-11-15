#include <iostream>
#include <cmath>

using namespace std;

/*
int isInteger(double value) //Проверка дабла на целочисленность. fmod не работает. Как и эта хуйня
{
	double temp;

	temp = round(value);

	cout << temp << "|||" << value << endl;

	cout << fmod(temp, temp) << endl;

	if (fmod(value, temp) == temp || fmod(value, temp) == 0)
		return (0);
	return (1);
} */

int isInteger(double value)
{

	cout << value << "///" << round(value) << endl;

	return !(value == trunc(value));
}

int stepSize_check(double step, double startNum, double endNum) //TODO: проверка на максимальный размер шага
{
	double mod;

	mod = (endNum - startNum) / step;

	cout << "mod: " << mod << endl;

	if (isInteger(mod))
		return (1);
	return (0);
}

int main()
{

	double a = 2;
	double b = 4;
	double h = 0.1;

	cout << "result: " << endl << stepSize_check(h, a, b) << endl;

	return (0);
}
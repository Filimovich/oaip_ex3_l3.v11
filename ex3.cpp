#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*ОБЪЯВЛЕНИЕ ПРОТОТИПОВ*/
double func_sum(double x);
double func_yx(double x);
int check_delta(double y, double sum);
int* iteration_counter(int flag);
double factorial(double arg);
void input_error(void);
int doubleOverflow_error(double digit);
void inputOutOfRange_error();
double digit_input();
int stepSize_check(double step, double startNum, double endNum);
int stepInputValidation(double step, double startNum, double endNum);
/*КОНЕЦ ОБЪЯВЛЕНИЯ ПРОТОТИПОВ*/

double factorial(double arg)
{
	if (arg == 0)
		return (1);

	double result;

	result = arg;

	while (arg > 1) {
		result *= --arg;
	}

	return (result);
}

double func_yx(double x)
{
	return ((pow(x, 2) / 4 + x / 2 + 1) * pow(M_E, (x / 2)));
}

double func_sum(double x) //TODO: добавить проверку stepsize > mod(start, end)
{
	double sum;
	double k;

	k = 0;
	sum = 0;

	while (check_delta(func_yx(x), sum)) {
		sum += (((pow(k, 2) + 1) / /*tgamma(k + 1))*/ factorial(k)) * pow((x / 2), k));
		k++;
		iteration_counter(1);
	}
	
	return (sum);
}

int* iteration_counter(int flag) //TODO: переделать через указатели
{
	static int i;

	if (flag == 0)
		i = 0;
	if (flag == 1)
		i++;
	if (flag == 2)
		return (&i);

	return (0);
	
	/*
	int counterValue;

	if (flag == 0){ // Флаг 0 - инициализация или сброс
		counterValue = 0;
		return (0);
	}

	if (flag == 1) { // Флаг 1 - итерация счетчика
		counterValue++;
		return (0);
	}

	if (flag == 2) { // Флаг 2 - вывод текущего состояния счетчика
		return (counterValue);
	}

	cout << "Wrong flag!" << endl; // Ошибка неверного флага */
}

int check_delta(double y, double sum)
{
	if (fabs(y - sum) > 0.0001)
		return (1);
	return (0);
}

void input_error(void)
{
	cout << "Input data type error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

void inputOutOfRange_error()
{
	cout << "Out of range error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

double digit_input()
{
	double digit;
	while(1) {
		string str;
		size_t pos{};
		cin >> str;
		try {
			digit = stod(str, &pos);
			if (cin && pos == str.size())
				break;
			else {
				input_error();
			}
		}
		catch (invalid_argument const&) {
			input_error();
		}
		catch (out_of_range const&) {
			inputOutOfRange_error();
		}
	}

	return (digit);
}

int doubleOverflow_error(double digit)
{
	if (isnan(digit)) {
		cout << "Overflow error. Try again." << endl;
		return (1);
	}
	return (0);
}

/*int isInteger(double value) //Проверка дабла на целочисленность. fmod не работает.
{
	int temp1 = value;
	double temp2 = value - temp1;
	temp1 = value;
	temp2 = value - temp1;
	if (temp2 == 0)
		return (0);
	return (1);
}

int stepSize_check(double step, double startNum, double endNum) //TODO: проверка на максимальный размер шага??
{
	double mod;

	mod = fabs(startNum - endNum) / step;

	if (isInteger(mod))
		return (1);
	return (0);
}*/ //!!НЕ РАБОТАЕТ! ХЗ ПОЧЕМУ! Ответ: проблема с представлением десятичных дробей в двоичном формате.

int isDoubleInt(double num)
{
	double precision;
	precision = 0.000000000001; // Обычно десятичная дробь ломается в районе 13-16 знака после запятой.

	if (fabs(num - round(num)) < precision)
		return 0;
	return 1;
}

int stepMode(double startNum, double endNum)
{
	if (startNum < endNum)
		return (1);
	if (startNum > endNum)
		return (-1);

	cout << "STEP ERROR" << endl;
	return(0);
}

int step_check(double step, double startNum, double endNum)
{
	double value;

	value = fabs(startNum - endNum) / step;

	if (isDoubleInt(value)) {
		cout << "Wrong step value. Try again." << endl;
		return (1);
	}

	return (0);
}

void printResultHeader()
{
	cout << endl << "---------------------------------------------------------------------" << endl;
	cout << "Step  |  ";
	cout << "Y(x)  |  ";
	cout << "S(x)  |  ";
	cout << "|Y(x) - S(x)|  |  ";
	cout << "S(x) Iterations count";
	cout << endl << "=====================================================================" << endl;
	//cout << "---------------------------------------------------------------------" << endl;
}

void printResult(int i, double x, double y, double eps, int count)
{
	cout << i << "  |  ";
	cout << y << "  |  ";
	cout << x << "  |  ";
	cout << fixed << eps << "  |  ";
	cout << count;
	cout << endl << "---------------------------------------------------------------------" << endl;
}

int main()
{
	double x; // x
	double y; // y
	double startNum; // a (ПОЛУЧАЕМ ИЗ КОНСОЛИ)
	double endNum; // b (ПОЛУЧАЕМ ИЗ КОНСОЛИ)
	double step; // h (ПОЛУЧАЕМ ИЗ КОНСОЛИ)
	double epsilon; // |Y(x) - S(x)|
	double iteration;

	iteration = 0;
	step = 0;

	cout << "Enter starting value: " << endl;
	startNum = digit_input();
	cout << "Enter final value: " << endl;
	endNum = digit_input();

	if (startNum != endNum) { // Если начало и конец равны, то шаг не нужен. Будет всего одна основная итерация
		do {
			cout << "Enter step size: " << endl;
			step = fabs(digit_input()) * stepMode(startNum, endNum);
		} while (step_check(step, startNum, endNum));
	}

	printResultHeader();

	do {
		iteration_counter(0);
		x = func_sum(startNum);
		y = func_yx(startNum);
		epsilon = fabs(y - x);
		startNum += step;

		printResult((++iteration), x, y, epsilon, *iteration_counter(2));

	} while (fabs(startNum - endNum - step) > 0.000000000001);

	return (0);
}
#include<iostream>
#include<cmath>
#include"taylor.h"
#include<time.h>
using namespace std;

double taylor_x_y(double x, double y);


int main()
{
	double x, y;
	cin >> x >> y;

	double result1 = taylor_x_y(x, y);
	double result2 = pow(x, y);

	long temp = clock();
	for (int i = 0; i < 10000; i++)
	{
		result1 = taylor_x_y(x, y);
	}
	temp = clock() - temp;

	cout.precision(15);

	cout << result1 << endl;
	cout << result2 << endl;
	cout << result2 - result1 << endl;
	cout << temp << endl;
	system("pause");
	return 0;
}

double taylor_x_y(double x, double y)
{
	int counter = 0;

	double power = y*( taylor_ln_x(x) + counter);

	return taylor_exp_x(power);
}
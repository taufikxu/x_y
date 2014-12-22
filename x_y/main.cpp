#include<iostream>
#include<cmath>
#include"taylor.h"
#include"newton.h"
#include"asm_pow.h"
#include"ODE.h"
#include<time.h>
using namespace std;

double taylor_x_y(double x, double y);
#define looptimes 1000000


int main()
{
	double x, y;
	double result;

	//cin >> x >> y;
	double max = 0, maxx = 0, maxy =0;
	x = 5;
	y = 2.7;

	cout.precision(15);
	{
		long temp = clock();
		for (int i = 0; i < 1000000; i++)
		{
			result = pow_x_y(x,y);
		}
		cout << "newton function:" << clock() - temp << "  error is:	" << result - pow(x,y) << endl;
	}
	//{
	//	long temp = clock();
	//	for (int i = 0; i < 1000000; i++)
	//	{
	//		result = taylor_ln_x_fast(x);
	//	}
	//	cout << "taylor fast function:" << clock() - temp << "  error is:" << result - log(x) << endl;
	//}
	//{
	//	long temp = clock();
	//	for (int i = 0; i < 1000000; i++)
	//	{
	//		result = int_ln_x(x);
	//	}
	//	cout << "int function:" << clock() - temp << "  error is:" << result - log(x) << endl;
	//	
	//}
	//{
	//	long temp = clock();
	//	for (int i = 0; i < 1000000; i++)
	//	{
	//		result = newton_ln_x(x);
	//	}
	//	cout << "newton function:" << clock() - temp << "  error is:" << result - log(x) << endl;
	//}
	{
		long temp = clock();
		for (int i = 0; i < 1000000; i++)
		{
			result = pow(x,y);
		}
		cout << "system function:" << clock() - temp << "  error is:" << result - pow(x,y) << endl;
	}
	////cout << taylor_x_y(x, y) -pow(x,y)<< endl;

	system("pause");
	return 0;
}

double taylor_x_y(double x, double y)
{
//	double power = y* newton_ln_x(x);
//	double power = y*int_ln_x(x);
//	double power = y*taylor_ln_x(x);
	if (y == 0)
		return 1;
	if (x == 0)
		return 0;

	double power = y*taylor_ln_x_fast(x);
	double temp = power - y*log(x);
	return taylor_exp_x(power);
}




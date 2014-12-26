#ifndef _improved_newton_h_
#define _improved_newton_h_

#include"taylor.h"

float MySqrt(float x)
{
	//float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	return 1/x;
}

double newton_sqrt_1_10(double x, double error = 1e-13)
{
	double g = MySqrt(MySqrt(MySqrt(x)));//给出一个预计值
	double x_n = g - 10, x_n_1 = g;
	while (x_n - x_n_1 > error || x_n_1 - x_n > error)
	{
		double x_9 = power_int(x_n_1, 9);
		x_n = x_n_1;
		x_n_1 = x_n - 0.1*(x_n*x_9 - x)/x_9;
	}
	return x_n_1;
}

double newton_improved_x_y(double x, double y, double error = 1e-11)
{
	if (y == 0)
		return 1;
	if (x == 0)
		return 0;

	int interg = round(y);
	int counter = 0;
	double result = 1;

	while ((y > 1e-6 || y < -1e-6) && counter < 6)
	{
		result *= power_int(x, interg);
		x = newton_sqrt_1_10(x);

		y = (y - interg)*10;
		interg = round(y);
		counter++;
	}
	return result;
}


#endif
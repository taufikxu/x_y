#ifndef _newton_h_
#define _newton_h_

#include"taylor.h"

double newton_ln_x(double x, double error = 1e-13)
{
	double counter = 0;
	while (x > 0.5)
	{
		x /= const_e;
		counter++;
	}

	double xk = x-1, xk_1 = 0;
	while (xk - xk_1 > error || xk_1 - xk > error)
	{
		xk_1 = xk;
		double fx = taylor_exp_x(xk_1);
		//fx = exp(xk_1);
		xk = xk_1 - ((fx - x) / fx);
	}
	return xk + counter;


}


double newton_x_y(double x, double y, double error = 1e-13)
{
	long inter = long(y);
	y -= inter;

	int dnum = 1;
	while (fabs(y - round(y)) > error)
	{
		y *= 10;
		dnum *= 10;
	}
	y = round(y);

	double factor = power(x, long(y));
	double xk = x, xk_1 = 0;
	while (fabs(xk - xk_1) > error)
	{
		xk_1 = xk;
		xk = xk - (power(xk, dnum) - factor) / (dnum*power(xk, dnum - 1));
	}
	return xk*power(x, inter);
}


#endif
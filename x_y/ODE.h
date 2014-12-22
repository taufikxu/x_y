#ifndef _ode_h_
#define _ode_h_

#include"taylor.h"
#include<math.h>

//利用微分方程求解

double OdeItera(double x, double y, double error = 1e-10)
{
	error /= 100;
	double ln_x = taylor_ln_x_fast(x);
	int store_y = int(y);
	y -= store_y;

	double step = sqrt(error / x / x / power_int(ln_x, 3));
	double bound = 0;

	double x_n = 0, y_n = 1;
	double y_n_1_temp, y_n_1;

	while (bound < y)
	{
		y_n_1_temp = y_n + step*(ln_x * y_n);
		y_n_1 = y_n + step * (ln_x*y_n + ln_x*y_n_1_temp) / 2;

		bound += step;
		y_n = y_n_1;
	}

	return y_n*power_int(x, store_y);
}

#endif
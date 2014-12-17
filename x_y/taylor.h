#ifndef _taylor_h_
#define _taylor_h_

#define const_e 2.718281828459045235360287471353

double power(double x, int n)
{
	double result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= x;
	}
	return result;
}

double taylor_ln_at_1(double x, double x_n, double n, double n_n)
{
	if (x > 1 || x < -1)
		return -1;
	
	if ( (int(n) & 1) == 1)
		return x_n / n;
	else
		return -x_n / n;
}

double taylor_exp_at_0(double x, double x_n, double n, double n_n)
{
	return x_n / n_n;
}

double UseTaylorGet(double(*taylor)(double, double, double, double), double x, double at_x, double init, double error)
{
	x -= at_x;
	double result = init;
	double itera = 1000000;
	double counter = 1;
	double x_n = x;
	double n_n = 1;

	while (itera > error || itera < -error)
	{
		itera = taylor(x, x_n, counter, n_n);
		result += itera;

		counter++;
		n_n *= counter;
		x_n *= x;
	}
	return result;
}

double taylor_ln_x(double x, double error = 1e-13)
{
	//if (x < 0)
	//	return -1;

	//return UseTaylorGet(taylor_ln_at_1, x, 1, 0, 1e-13);
	int counter = 0;
	if (x >= 1.5)
	{
		while (x >= 1.5)
		{
			x /= const_e;
			counter++;
		}
	}
	if (x <= 0.5)
	{
		while (x <= 0.5)
		{
			x *= const_e;
			counter--;
		}
	}
	

	x -= 1;
	double result = 0;
	double itera = 10;
	int loop_counter = 1;
	double x_n = x;


	while (itera > error || itera < -error)
	{
		itera = taylor_ln_at_1(x, x_n, loop_counter, 0);
		result += itera;
		
		loop_counter++;
		x_n *= x;
	}

	return result + counter;
}

double taylor_exp_x(double x)
{
	int store = int(x);
	x = x - store;

	double result = 1;
	double itera = 10;
	double x_n = x;
	double n_n = 1;
	int counter = 1;
	double error = 1e-11 / power(const_e, int(x) + 1);

	

	while (itera > error/2 )
	{
		itera = taylor_exp_at_0(x, x_n, 0, n_n);
		result += itera;

		counter++;
		n_n *= counter;
		x_n *= x;
	}
	return result*power(const_e, store);
}

#endif
#ifndef _taylor_h_
#define _taylor_h_

#define const_e 2.718281828459045235360287471353

int normolize(double &x, double low = 0.5, double high = 1.5)//归一化函数，将x整理到low-high的区间上。
{
	int counter = 0;
	if (x > high)
	{
		while (x >= high)
		{
			x /= const_e;
			counter++;
		}
	}
	if (x <= low)
	{
		while (x <= low)
		{
			x *= const_e;
			counter--;
		}
	}
	return counter;
} 

double power_int(double x, int n) //对指数为整数时，直接做运算。该运算的复杂度为logn，而非n
{
	unsigned int _N = n;
	if (n < 0)
		_N = -n;

	for (double result=1; ; x *= x)
	{
		if ((_N & 1) == 1)
			result *= x;
		if ((_N >>= 1) == 0)
			return n>0 ? result : 1 / result;
	}
	return 0;
}

double taylor_ln_at_1(double x, double x_n, double n, double n_n) //对ln(1+x)的泰勒展开
{
	if ( (int(n) & 1) == 1)
		return x_n / n;
	else
		return -x_n / n;
}

double taylor_exp_at_0(double x, double x_n, double n, double n_n)//e^x的泰勒展开
{
	return x_n / n_n;
}

double taylor_ln_x(double x, double error = 1e-13) //利用taylor展开求解ln(x)
{
	if (x <= 0)
		return 0;

	int counter = normolize(x);
	
	x -= 1;
	double result = 0;
	double itera = 10;
	int loop_counter = 1;
	double x_n = x;


	while (x_n > error/2 || x_n < -error/2 )
	{
		itera = taylor_ln_at_1(x, x_n, loop_counter, 0);
		result += itera;
		
		loop_counter++;
		x_n *= x;
	}

	return result + counter;
}

double taylor_ln_x_fast(double x, double error = 1e-13) //利用加速的taylor展开求解ln(x)
{
	if (x <= 0)
		return 0;

	int counter = normolize(x);

	double result = 0;
	double itera = 10;
	int loop_counter = 1;

	x = (x - 1) / (x + 1);
	double x_n = x;


	while (x_n > error / 2 || x_n < -error / 2)
	{
		itera = x_n/loop_counter;
		result += itera;

		loop_counter += 2;
		x_n *= (x*x);
	}

	return result*2 + counter;
}

double taylor_exp_x(double x, double error = 1e-11)//利用taylor展开求解e^x
{
	int store = int(x);
	x = x - store;

	double result = 1;
	double itera = 10;
	double x_n = x;
	double n_n = 1;
	int counter = 1;
	
	error = error / power_int(const_e, store > 0 ? store : 1);

	while (itera > error/2 || itera < -error/2)
	{
		itera = taylor_exp_at_0(x, x_n, 0, n_n);
		result += itera;

		counter++;
		n_n *= counter;
		x_n *= x;
	}
	return result*power_int(const_e, store);
}

double int_ln_x(double x, double error = 1e-13) //利用积分求解ln(x)
{
	if (x <= 0)
		return 0;

	int counter = normolize(x);
	
	bool flag = x > 1;
	if (!flag)
		x = 1.0 / x;

	long step_num = (x - 1) / 0.0001;
	double step = (x - 1) / (step_num + (step_num & 1));

	double result = 1;
	double bound = 1;
	while (fabs(bound-x)>step/2)
	{
		bound += step;
		result += 4 / bound;
		bound += step;
		result += 2 / bound;
	}
	result = (result - 1 / x)*step / 3;
	if (flag)
		return result + counter;
	else
		return -result + counter;
	
}

#endif
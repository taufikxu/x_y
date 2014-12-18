#include<iostream>
#include<cmath>
#include"taylor.h"
#include"newton.h"
#include<time.h>
using namespace std;

double taylor_x_y(double x, double y);

#include"test.h"

int main()
{
	double x, y;
	double result;

	cin >> x >> y;
	//cout << newton_x_y(x, y) - pow(x, y) << endl;
	//system("pause");
	//return 0;



	long temp = clock();
	double aa = pow_x_y(x, y);
	for (int i = 0; i < 100000; i++)
	{
		result = taylor_x_y(x, y);
	}
	cout << clock() - temp << endl;
	cout << result -pow(x,y)<< endl;

	system("pause");
	return 0;
}

double taylor_x_y(double x, double y)
{
	double power = y* newton_ln_x(x);
	//double power = y*taylor_ln_x(x);
	return taylor_exp_x(power);
}




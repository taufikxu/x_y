#include<iostream>
#include<cmath>
#include<time.h>
#include<cstring>
#include"taylor.h"
#include"newton.h"
#include"improved_newton.h"
#include"asm_pow.h"
#include"ODE.h"

using namespace std;

#define looptimes 1000000

int main()
{
	double x, y;
	double result;

	double max = 0;
	double maxx = 0, maxy = 0;

	cin >> x >> y;
	cout.precision(15);
	{
		long temp = clock();
		for (int i = 0; i < 1000000; i++)
		{
			result = newton_improved_x_y(x, y);
			//result = pow(x, y);
			//result = taylor_x_y(x, y);
		}
		cout << "newton_improved function:" << clock() - temp << "\terror is" << result - pow(x, y) << endl;
	}
	{
		long temp = clock();
		for (int i = 0; i < 1000000; i++)
		{
			//result = newton_improved_x_y(x, y);
			result = pow(x, y);
			//result = taylor_x_y(x, y);
		}
		cout << "system function:" << clock() - temp << "\terror is" << result - pow(x, y) << endl;
	}
	
	

	//cout << newton_improved_x_y(x, y) - pow(x, y) << endl;
	
	system("pause");
	return 0;
}






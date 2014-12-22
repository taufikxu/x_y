#ifndef _test_h_
#define _test_h_

/*
利用汇编指令求取x^y，该部分有汇编指令，其汇编的格式遵从vs2012的方式。如果使用devC++或其他编译器请重写此部分代码
*/
double y_log_2_x(double x, double y)
{
	double ret1;
	__asm fld y;
	__asm fld x;
	__asm fyl2x;
	__asm fstp ret1;
	return ret1;

}

double pow_x_y(double x, double y)
{
	double y_log_x = y_log_2_x(x, y);
	long temp = long(y_log_x);
	double temp_d = y_log_x - temp;
	
	__asm fld temp_d;
	__asm f2xm1;
	__asm fstp temp_d;
	double result = (temp_d + 1)*(1 << temp);
	return result;
}
#endif
// C2.1.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
double func(double x, int n) {
	double z=x;
	for (; n >1; n--)
	{
		z *= x;
	}return z;
}
int main()
{
	double x ;
	int n ;
	//scanf_s("%f %d", &x, &n);
	std::cin >> x;
	std::cin >> n;
	printf("%f ^ %d = %f\n", x, n, func(x, n));
	getchar();
	getchar();
	getchar();
	getchar();
    return 0;
}


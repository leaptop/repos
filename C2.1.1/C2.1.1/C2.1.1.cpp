#include "stdafx.h"
#include <iostream>
int factorial(int i) {
	if (i >= 0) {
		int rez = 1;
		for (int y = i; y > 1; y--) rez *= y;
		return rez;
	}
	else printf("Факториал берём от числа больше нуля");
}
double cosinus(double j) {
	double rez = 0;
	double x = j;
	for (int n = 0; n < 9; n++)
	{
		rez += (pow(-1.0, n)*pow(x, n * 2)) / (factorial(n * 2));
	}
	return rez;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double a = 3.1;
	printf("cosinus %f = %8.4f\n", a, cosinus(a));
	printf("cos     %f = %8.4f\n", a, cos(a));
	getchar();
	return 0;
}

//#include "stdafx.h"
//#include <math.h>
//#include <stdio.h>
//#include <clocale>
//float cosinus(float x) {
//	float Cos = 1., eps; int i;
//	for (i = 1, eps = 1; (eps>0.0001) || (eps<-0.0001); i++) {
//		eps = 1; //printf("eps1 = %f\n", eps);
//		for (int f = 1; f <= i * 2; f++) {
//			eps *= x / f;
//			//printf("eps2 = %f\n", eps);
//		}
//		if (i % 2) eps *= (-1.); //printf("eps3 = %f\n", eps); 
//		Cos += eps;//printf("cosP = %f\n", Cos);
//	}
//	return Cos;
//}
//int main() {
//	setlocale(LC_ALL, "Russian");
//	float x, y; printf("ведите х");
//	scanf_s("%f", &x);
//	y = cos(x); printf("cos x= %f \n", y);
//	y = cosinus(x); printf("cosinus x= %f \n", y);
//	getchar();
//	getchar();
//	getchar();
//	getchar();
//	getchar();
//}

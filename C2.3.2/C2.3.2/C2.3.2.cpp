// C2.3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include<clocale>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#pragma warning( disable : 4996 ) 

int main()
{
	setlocale(LC_ALL, "Russian");
	double x = -100, y = 100;
	double  *a;
	int n = 1;
	printf("Введите n\n");
	scanf("%d", &n);
	a = new double[n];
	double **b;
	b = new double *[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()*(y - x) / RAND_MAX + x;
		//a[i] *= 
		//printf("%f\n", a[i]);
		b[i] = &a[i];

	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (*b[j] > *b[j + 1]) {
				double *tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
		}
	}
	printf("array a: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%f\n", a[i]);
	}
	printf("array b: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%f\n", *b[i]);
	}
	std::getchar();
	std::getchar();
	std::getchar();
	std::getchar();
	return 0;
}

/*// C2.3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#pragma warning( disable : 4996 )
#include <clocale>
#include <string>
int random(int N) { return rand() % N; }
int main() {
	setlocale(LC_ALL, "Russian");
	int n, x = -50, y = 50, m = 0, k = 0;
	int *b, *c, *d;
	printf("Введите n(длина массива b)\n");
	scanf("%d", &n);
	b = (int *)malloc(n * sizeof(int));
	c = (int *)malloc(sizeof(int));
	d = (int *)malloc(sizeof(int));
	printf("Исходный массив\n");
	for (int i = 0; i < n; i++)
	{
		b[i] = random(y - x + 1) + x;
		printf("%d\n", b[i]);
		if (b[i] >= 0) { c[m] = b[i]; m++; }
		else { d[k] = b[i]; k++; }

	}
	printf("Положительные\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", c[i]);
	}
	printf("Отрицательные\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", d[i]);
	}

	std::getchar();
	std::getchar();
	return 0;
}

*/
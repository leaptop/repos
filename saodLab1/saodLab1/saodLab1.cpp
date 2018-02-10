#include "stdafx.h"
#include <time.h>
#include<stdlib.h>// for srand
#include <iostream>
#include<conio.h>//for _getch()

using namespace std;
/*Лабораторная работа № 1

1). Дан массив А из n целых чисел. 
Разработать шесть сервисных процедур, которые будут использованы в следующих лабораторных работах:
    a) процедуру FillInc, заполняющую массив А возрастающими числами.
    b) процедуру FillDec, заполняющую массив А убывающими числами.
    c) процедуру FillRand, заполняющую массив А случайными числами.
    d) функцию CheckSum для подсчета контрольной суммы элементов массива А.
    e) функцию RunNumber  для подсчета серий в массиве А.
    f) процедуру PrintMas для вывода  на  экран  элементов  массива А.

Массив А и кол-во n – параметры процедур !!!
*/
void FillInc(int *a, int n) {
	
	if (n > 0)a[0] = rand() % 100; else return;
	cout.width(5);
	cout << a[0] << " ";
	for (int i = 1; i < n; i++)
	{
		cout.width(5);
		a[i] = a[i-1]+rand() % 100;
		cout << a[i] << " ";
	}
}
int main()
{
	srand(time(0));
	int *a, n =10;
	a = new int[n];
	FillInc(a, n);
	cout <<endl;
	FillInc(a, n);
	_getch();
    return 0;
}


#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

void f(int** mass, int s, int c) {//creation of the second array and summation
	//int a, b, d;
	for (int i = 0; i < s; i++)
	{
		for (int q = 1; q < c; q++)
		{
			mass[i][0] += mass[i][q];
		}
	}
}
int main()
{
	srand(time(0));
	int **mass, a, b, s, c, d, e;
	cout << "insert a number of strings and a number of columns\n";
	cin >> s >> c;
	mass = new  int*[s];
	cout << "the original array\n";
	for (int i = 0; i < s; i++)//array initiation
	{
		mass[i] = new int[c];
		for (int q = 0; q < c; q++)
		{
			mass[i][q] = rand() % 100;
			cout.width(3);
			cout << mass[i][q] << " ";
		}cout << endl;
	}
	cout << endl << "counted\n";
	f(mass, s, c);
	for (int i = 0; i < s; i++)
	{
		for (int q = 0; q < c; q++)
		{
			cout.width(4);
			cout << mass[i][q] << " ";
		}cout << endl;
	}
	_getch();
	return 0;
}


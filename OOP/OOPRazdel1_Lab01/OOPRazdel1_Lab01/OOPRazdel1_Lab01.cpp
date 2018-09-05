#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>//for cout(for C++ only)
using namespace std;// for cout(for C++ only)
char random(char N) { return rand() % N; }
void sortA(char **matr, char *final, int str, int stl) {//works only for square matrix
	int v = 0, st = 0, sl = stl, num = str * stl;
	int sll = stl;
	for (sl = stl - 1; sl >= 0; sl--)// sl - a number of passes(diagonals)
	{
		int sll = sl;
		while (sll < stl) {//for this type of viborka it will be needed to use nonexistent indexes...
			//(if I want to do it in one cycle)
			final[v] = matr[st][sll];
			v++; st++; sll++;
		}
		st = 0;
	}
	sl = 0;
	for (st = 1; st < str; st++)// sl - a number of passes(diagonals)
	{
		int stt = st;
		while (stt < str) {
			final[v] = matr[stt][sl];
			v++; stt++; sl++;
		}
		sl = 0;
	}
}
void sortB(char **matr, char *final, int str, int stl) {
	int v = 0, st = 0, sl = stl, num = str * stl;
	int sll = stl;
	for (sl = 0; sl < stl; sl++)
	{
		int sll = sl;
		while (sll >= 0) {
			final[v] = matr[st][sll];
			v++; st++; sll--;
		}
		st = 0;
	}
	sl = stl - 1;
	for (st = 1; st < str; st++)
	{
		int stt = st;
		while (stt < str) {
			final[v] = matr[stt][sl];
			v++; stt++; sl--;
		}
		sl = stl - 1;
	}
}

int main()
{
	srand(time(NULL));
	int str = 5, stl = 5;
	char l = 120, k = -30;
	char **matr;
	char *final;// matr - указатель на массив указателей
	final = new char[str*stl];

	matr = new char*[str];// выделяем память под массив указателей
	for (int i = 0; i < str; i++)
	{
		matr[i] = new char[stl];// Выделяем память под i-ю строку
		for (int j = 0; j < stl; j++)
		{
			matr[i][j] = rand() % 90;
			int g = matr[i][j];
			cout.width(4);
			cout << g << " ";

		}
		cout << endl;
	}
	sortB(matr, final, str, stl);
	for (int i = 0; i < str*stl; i++)
	{
		int s = final[i];
		cout << s << " ";
	}
	getchar();
	return 0;
}


#include "stdafx.h"
#include <clocale>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include<time.h>
using namespace std;
/*    1. Дана информация о  школах города.
Запись имеет вид: номер школы, количество выпускников школы,
число поступивших в ВУЗ. Сформировать массив из записей и
отсортировать его с помощью индексного масссива по количеству поступивших в ВУЗы. Вывести
данные о количестве выпускников по каждой школе и доле поступивших в ВУЗ.*/
int random(int N) { return rand() % N; }
int main() {
	srand(time(0));
	const int numOfSchools = 10;
	struct school { int ns; int ng; int np; }t;//t здесь объявление ссылки на область памяти. Эта запись равносильна такой struct school { int ns; int ng; int np; }; struct school t; school - описание(шаблон структуры)
	struct school mag[numOfSchools];
	int a = 10, b = 60, x = 60, y = 110;
	cout.width(15); cout << "School";	cout.width(15); cout << "Vipusknikov";	cout.width(15); cout << "Postupivshih\n";
	for (int i = 1; i <= numOfSchools; i++)
	{
		mag[i].ns = i;
		cout.width(15);	cout << mag[i].ns;
		mag[i].ng = random(y - x + 1) + x;
		cout.width(15);	cout << mag[i].ng;
		mag[i].np = random(b - a + 1) + a;
		cout.width(15);	cout << mag[i].np<<endl;
	}
	cout << endl << "--------------------------------------------------------------\n";
	for (int i = 1; i < numOfSchools ; i++) {
		for (int j = 1; j < numOfSchools  ; j++) {
			if (mag[j].np < mag[j + 1].np) {
				school tmp = mag[j];
				mag[j] = mag[j + 1];
				mag[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 1; i < numOfSchools+1; i++)
	{

		cout.width(15);	cout << mag[i].ns;	cout.width(15); cout << mag[i].ng;	cout.width(15);cout << mag[i].np << endl;
	}
	_getch();
}
//#define n 10
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int i, k; float sum; //k-количество искомых товаров, sum- их общая стоимость.
//	struct tov { char name[10]; float c; int kol; } t;  //Объявление структуры t
//	struct tov mag[n];  //объявление массива структур mag[n]
//	char nazv[10]; //Наименование искомого товара
//	printf("\n Введите информацию о товарах \n");
//	for (i = 0; i<n; i++)
//	{
//		printf("\n  наименование , цена, количество :  ");
//		scanf_s("%s%f%d", &t.name, &t.c, &t.kol);//Заполнение информацией структуры t
//		mag[i] = t; //Присвоение i-му элементу массива структуры t целиком
//	}
//	printf("\n введите искомый товар:  ");
//	scanf_s("%s", &nazv);
//	for (i = 0, sum = 0, k = 0; i<n; i++)
//		if (strcmp(mag[i].name, nazv) == 0)
//		{
//			sum += mag[i].c*mag[i].kol;
//			k++;
//		}
//	printf("Товаров  %s   %d,  их стоимость  %5.2f ", nazv, k, sum);
//	_getch();
//}


//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	struct card { char author[40]; char title[40]; int  year; float  cena; };
//	struct card Book;
//	strcpy_s(Book.author, "Довгаль С.И.");
//	strcpy_s(Book.title, "Турбо Паскаль V 7.0");
//	Book.year = 2003;
//	Book.cena = 125;
//	printf("%s %s %d год цена %5.2f", Book.title, Book.author, Book.year, Book.cena);
//	_getch();
//	return 0;
//}




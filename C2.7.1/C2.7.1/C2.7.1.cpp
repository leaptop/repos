#include "stdafx.h"
#include <clocale>
#include<cstdlib>// for rand
#include<conio.h>
#include<iostream>
#include<time.h>
using namespace std;
/*1. Написать функцию, сортирующую в порядке убывания элементы одномерного массива.
В главной программе вызвать функцию для двух разных по количеству элементов массивов N=100 и  N=1000.
Написать две функции поиска заданных элементов в каждом из отсортированных массивов –
перебором и бинарным поиском. Вывести количество операций сравнения в каждой функции.
*/

void f(int* a, int n) {//aligner
	for (int i = 0; i < n - 1; i++) {
		// сравниваем два соседних элемента.
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				// если они идут в неправильном порядке, то  
				//  меняем их местами. 
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void fn(int* a, int n) {//filler
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		//printf("%d ", a[i]);
	}
}
int find(int c, int* a, int al) {//поиск перебором
	int i = 0;
	for (i = 0; i < al; i++) {
		if (a[i] == c) {
			cout << "\nfound " << c << "; ";			return i+1;
		}
	}if (i == al) {
		cout << "\nhaven't found " << c; return i+1;
	}
}
int findBin(int c, int*a, int al) {
	int n = 0, k = al, i = 1;
	while (true) {
		i++;
		if (a[(n + k) / 2] > c) {//если с меньше элемента из серединки, то с находится правее серединки и левой границей поиска становится эта серединка. Всё элементарно.
			n = (n + k) / 2;
		}
		else if (a[(n + k) / 2] < c) {
			k = (n + k) / 2;
		}
		else if (a[(n + k) / 2] == c) {
			cout << endl << "\nfound(binary) " << c << "; "; return i;
		}
		else {
			cout << endl << "\nhaven't found(binary) " << c; return i;
		}

	}

}
int main()
{
	srand(time(0));
	int  *a, *b, n = 100, N = 10000;
	a = new int[n];
	b = new int[N];
	fn(a, n);
	f(a, n);
	fn(b, N);
	f(b, N);


	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i] << " ";
	//}//int y[]  = { 3,6,4,9,0 };
	////find(10, y, 5);
	//for (int i = 0; i < N; i++)
	//{
	//	//cout << b[i] << " ";
	//}
	cout << endl << "i= " << findBin(25, b, N);
	_getch();
	return 0;
}

/*Лабораторная работа №7

Массивы как параметры функций


1. Цель работы:  Изучение методов передачи  параметров-массивов в  функции.

2. Основные сведения
Стандартным способом передачи аргументов в функцию является передача по значению,
т. е. создание в функции их локальных копий. При этом аргументы  не могут изменяться.
Массив же в С++ никогда не передается по значению, а только как указатель на его первый,
точнее нулевой, элемент. Например, объявление
void print( int[ 10 ] );
рассматривается компилятором так, как будто оно имеет вид
void print( int * );
Размер массива неважен при объявлении этого параметра. Все три приведенные записи эквивалентны:
 void print( int* );
 void print( int[] );
 void print( int[ 10 ] );
Передача массивов как указателей имеет следующие особенности:
изменение значения аргумента внутри функции затрагивает сам переданный объект,
а не его локальную копию. Если такое поведение нежелательно,
программист должен позаботиться о сохранении исходного значения.
Можно также при объявлении функции указать, что она не должна изменять
значение параметра, объявив этот параметр константой:
void print( const int[ ] );
 Cи-строка является массивом символов, последний элемент которого равен нулю.
 Во всех остальных случаях при передаче массива в качестве параметра
 необходимо указывать его размер. Обычно для такого указания используют
 дополнительный параметр функции. Например:
void print( int *, int size );
Параметр может быть многомерным массивом. Для такого параметра должны быть
заданы правые границы всех измерений, кроме первого. Например:
void print( int matrix[][10], int rowSize );
Здесь matrix объявляется как двумерный массив, который содержит десять столбцов
и  число строк, передаваемое отдельным параметром. Эквивалентным объявлением для matrix будет:
int (*matrix)[10];
Многомерный массив передается как указатель на его нулевой элемент.
В нашем случае тип matrix – указатель на массив из десяти элементов типа int.
Как и для одномерного массива, граница первого измерения не учитывается
при проверке типов. Если параметры являются многомерными массивами,
то контролируются все измерения, кроме первого. Заметим, что скобки
вокруг *matrix необходимы из-за более высокого приоритета операции взятия индекса. Инструкция
int *matrix[10];
объявляет matrix как массив из десяти указателей на int.
Если массив описан как **m или *m[N] при передаче его в качестве параметра
используется описание вида **a или *a[]


void f(int **a, int n, int m) {
	 for(int i=0;i<n; i++) {
	   for(int j=0;j<m; j++)  printf("%5d",a[i][j]);
	   printf("\n");
	  }
}

f(a,5,4) – вызов
3. Примеры передачи массива в функцию
Пример 1. Рассмотрим функцию, вычисляющую сумму элементов массива.
*/
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
// int Sum ( int A[], int N ) 
// { 
//   int i, sum;
//   sum = 0;
//   for ( i = 0; i < N; i ++ )
//     sum += A[i];
//   return sum;
// }
//int main()
//{ 
//	setlocale(LC_ALL, "Russian");
//	const int n=20,m=30;
//   int i, s, A[n], B[m];
//   printf(" Массив A \n");
//   for (i=0; i<n; i++)
//   {  A[i]=rand()%10;
//      printf("%5d",A[i]);
//   }
//   printf("\n\n Массив B \n");   
//   for (i=0; i<m; i++)
//   {  B[i]=rand()%20;
//      printf("%5d",B[i]);
//   }
//   s = Sum(A,n); 
//   printf("\n\nСумма массива A %d,  массива B %d", s, Sum(B,m) ); 
//   _getch();
//   return 0;
//}
/*
Пример 2 :  Передача в функцию массива c использованием указателя.
Результат – элементы исходного массива возводятся в квадрат.
*/
//#include <stdio.h>
//#include <conio.h>
//void quart(int n, float * x)  
//{ int i;
//  for (i=0;i<n;i++)
//     x[i]=x[i]*x[i];
//}
//int main()
//{  float z[]={1,2,3,4,5}; 
//   int j; int n=sizeof(z)/sizeof(z[0]);
//   for (j=0; j<n; j++)
//   printf(" %6.2f",z[j]);
//   quart(n,z);
//   putchar('\n');
//   for (j=0; j<n; j++)
//       printf("\n %6.2f",z[j]);
//   _getch();
//}
/*
Пример 3.
 Написать функцию обработки матриц  A и B одинакового размера m x n.
 Получить матрицу C =max(A(i,j),B(i,j)), и матрицу D=min(A(i,j),B(i,j)).
 Матрицы C и D вывести в главной программе.
 */
 //#include <stdio.h>
 //#include <conio.h>
 //#include <stdlib.h>
 //
 //const int n=4,m=4;
 //void MaxMin(int A[][n],int B[][n],int (*C)[n], int (*D)[n],int m)
 //{  int i,j;
 //   for (i=0;i<m;i++)
 //     for (j=0;j<n;j++)
 //      if (A[i][j]>B[i][j])
 //      {  C[i][j]=A[i][j];
 //         D[i][j]=B[i][j];
 //      }
 //      else
 //      {  C[i][j]=B[i][j];
 //         D[i][j]=A[i][j];
 //      }   
 //    return;
 //}
 //int main ()
 //{ 
 //  int A[m][n],B[m][n],C[m][n],D[m][n],i,j;
 //         
 //  for (i=0;i<m;i++)
 //  {   for (j=0;j<n;j++)
 //     {  A[i][j]=rand()%20;
 //        printf("%5d",A[i][j]);
 //     }
 //     puts("\n");
 //  }
 //  puts("\n\n");
 //  for (i=0;i<m;i++)
 //  {   for (j=0;j<n;j++)
 //     {  B[i][j]=rand()%20;
 //        printf("%5d",B[i][j]);
 //     }
 //     puts("\n");
 //  }
 //  MaxMin(A,B,C,D,m);
 //  puts("\n\n");
 //  for (i=0;i<m;i++)
 //  {   for (j=0;j<n;j++)
 //     {  
 //        printf("%5d",C[i][j]);
 //     }
 //     puts("\n");
 //  }
 //  puts("\n\n");
 //  for (i=0;i<m;i++)
 //  {   for (j=0;j<n;j++)
 //     {  
 //        printf("%5d",D[i][j]);
 //     }
 //     puts("\n");
 //  }
 //  _getch();
 //  return 0;
 //}  

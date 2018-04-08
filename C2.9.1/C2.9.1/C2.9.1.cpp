#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>//  for cout
using namespace std;// for cout
#include<conio.h>// for _getch()
#include<stdlib.h>// for srand
#include<conio.h>//for _getch()

typedef struct st
{
	char data[20];
	struct st * next;
} spis;
spis * create(void); //функция создания списка
void list(spis *head); // функция просмотра списка
void free_spis(spis *head); //функция освобождения памяти
int main()
{
	system("CLS");
	spis *head; // адрес головы списка
	head = create();
	list(head);
	free_spis(head);
	_getch();
}
spis * create(void)
{
	spis *p, *pred, *h;
	// pred – указатель на предыдущую структуру
	// h- указатель на первую структуру
	h = pred = new spis; //выделение памяти для первой структуры
	printf("  fam: "); scanf_s("%s", pred->data);
	do {
		p = new spis;
		printf("\n  fam: "); scanf_s("%s", p->data);
		pred->next = p; //ссылка из предыдущей на текущую
		pred = p; // сохранение адреса текущей 
		printf(" закончить? y/n  ");
	} while (_getch() == 'y');
	p->next = NULL;
	return h;
}
void list(spis *head)
{
	spis *p;
	p = head;
	while (p != NULL) // пока не конец списка
	{
		printf("\n  fio: %s", p->data);
		p = p->next; // продвижение по списку 
	}
}
void free_spis(spis *head)
{
	spis *p, *q;
	q = p = head;
	while (p != NULL)
	{
		p = q->next;
		delete q;
		q = p;
	}
	head = NULL;
}


//typedef struct st
//{
//	char ch;
//	struct st *next;
//} stack;
//int main()
//{
//	stack *p, *q;
//	char a;
//	p = NULL;
//	system("CLS");
//	//  заполнение стека 
//	do
//	{
//		a = getchar();
//		q = (stack *)malloc(sizeof(stack));
//		q->next = p;// Обращение к полю структуры(вместо точки, так как структура динамическая)
//		p = q;
//		q->ch = a;
//	} while (a != '.');
//	//  печать стека c освобождением памяти
//	do
//	{
//		p = q->next;
//		free(q);
//		q = p;
//		printf("%c", p->ch);
//	} while (p->next != NULL);
//	_getch();
//	return 0;
//}
// OOPLabor2.cpp : Defines the entry point for the console application.
//
/*Объектно-ориентированное программирование

Занятие 2 Использование динамических структур
данных (список, стек, очередь)

Задание 1 Написать процедуры и функции для работы со списком
	A. добавление элемента после к-ого элемента списка // после к-го по счёту от head например
	B. удаление из списка к-ого элемента
	C. подсчет числа элементов в списке
	D. перемещение р-ого элемента списка после к-ого элемента
С помощью этих процедур и функций создать список следующим образом.
Включать в список полные квадраты из одномерного массива целых чисел (типа Byte).
Удалить повторяющиеся элементы списка. Определить длину полученного списка.

Задание 2 Написать программу, которая визуально демонстрирует работу стека и очереди.
Длина стека и очереди ограничена 10 элементами.

  0     1     2     3
tail               head

*/

#include "stdafx.h"

struct list {
	list* prev;
	list* next;
	int data;
	int count;
};
void A(list* nov, int &count, int k, list *head, list *tail, list *jump) {

	if (k > count) {
		nov = new list;
		nov->prev = head;
		head = nov;
	}
	else
		jump = head;
	while (jump->count > count && jump != tail)
	{
		jump = jump->prev;
	}if (jump == tail && tail->count > k) {
		nov->prev = NULL;
		nov->next = tail;
		tail = nov;
	}
	else {

	}
	nov->prev = jump;
	nov->next = jump->next;
	jump->prev;

}
void A_1( int k, list *head, list *tail, list *nov) {
	nov = tail;
	for (int i = 0; i < k ; i++)
	{
		nov = nov->next;
		if (nov->next == NULL) break;
	}
	
}

int main()
{

	return 0;
}


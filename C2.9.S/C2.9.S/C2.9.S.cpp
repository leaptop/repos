// C2.9.S.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>//  for cout(for C++ only)
#include<conio.h>// for _getch()
using namespace std;// for cout(for C++ only)

/*
Здесь будет реализован стек, отсортированный так, что Head указывает
на наименьший элемент(элемент, чьё поле name наименьшее).
*/

typedef struct Node {
	Node *next;
	char name[20];
	int m1, m2, m3, m4;

};
typedef Node *PNode;



//CreateNode(PNode Head) {//работает без сортировки
//	PNode NewNode = new Node;
//	cout << "Введите фамилию студента ";	
//	cin >> NewNode->name;
//	NewNode-> next = Head;//добавил в next значение внешней ссылки Head
//	Head = NewNode;//добавил во внешнюю ссылку Head адрес текущей структуры
//	return NewNode;
//}
//по идее мне надо более тяжёлые переставлять в начало списка

/*Эту функцию(findTheLastSmaller) уже попроще протестить. Лучше не гадать долго,
а начать уже тестировать. Моя задача - найти последний наибольший элемент списка
по отношению к новой структуре New(признак сравнения - поле name).
Т.о. я буду иметь ссылки на последний наибольший (возвращаемое значение) и на следующий,
(тот, который меньше искомого(на него можно сослаться так: возвращаемое значение -> next)).
*/
//По аналогии со стопкой тарелок начало списка называют основанием стека, а его конец — вершиной.
PNode findTheLastSmaller(PNode &st, PNode &New) {/*Уже известно, что Head меньше, чем New*/

	while (true) {/*Нужно найти последний, который легче нового, чтобы
						встать перед ним*/
		if (strcmp(st->name, New->name) <= 0 && st->next == NULL) {
			New->next = NULL; 
			st->next = New; 
			return NULL;
		}
		if (strcmp(st->name, New->name) < 0 &&
			strcmp(st->next->name, New->name) > 0) {
			return st;
		}
		//if (st->next != NULL)
		st = st->next;
	}
	return st;
}

PNode CreateNode(PNode &Head, PNode &NewNode, PNode &prohod, PNode &prohodPrev) {
	NewNode = new Node;
	PNode tlb;
	cout << "Введите фамилию студента ";
	cin >> NewNode->name;
	if (Head == NULL) { Head = NewNode; NewNode->next = NULL;  return Head; }
	if (strcmp(Head->name, NewNode->name) >= 0) {/* Если нейм головы уже больше,
												 то новый элемент списка надо >= поставить
												 тупо ставим в начало списка(перед Head),
												 а в Head прописываем адрес нового элемента*/
		NewNode->next = Head; Head = NewNode; return NULL;
	}
	/*Иначе находим последний наибольший.
	Head остаётся на месте(продолжает указывать на последний(наименьший) элемент.
	*/
	prohod = Head;
	tlb = findTheLastSmaller(prohod, NewNode);

	if(tlb!=NULL){
		NewNode->next = tlb->next;
		tlb->next = NewNode;
	}
	

	return NewNode;
}

int main()
{
	PNode Head = NULL, prohod = NULL, NewNode = NULL, prohodPrev = NULL;
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число студентов ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		CreateNode(Head, NewNode, prohod, prohodPrev);
	}
	prohod = Head;//prohod - временная переменная для прохода по списку
	for (int i = 0; i < n; i++) {
		cout << prohod->name << endl;
		prohod = prohod->next;
	}

	_getch();
	return 0;
}


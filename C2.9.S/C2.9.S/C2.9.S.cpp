// C2.9.S.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>//  for cout(for C++ only)
#include<conio.h>// for _getch()
using namespace std;// for cout(for C++ only)

typedef struct Node {
	Node *next;
	char name[20];
	int m1, m2, m3, m4;

};
typedef Node *PNode;


PNode

//CreateNode(PNode Head) {//работает без сортировки
//	PNode NewNode = new Node;
//	cout << "Введите фамилию студента ";	
//	cin >> NewNode->name;
//	NewNode-> next = Head;//добавил в next значение внешней ссылки Head
//	Head = NewNode;//добавил во внешнюю ссылку Head адрес текущей структуры
//	return NewNode;
//}

CreateNode(PNode &Head, PNode &NewNode, PNode &prohod, PNode &prohodPrev) {
	NewNode = new Node;
	cout << "Введите фамилию студента ";
	cin >> NewNode->name;
	if (Head == NULL) { Head = NewNode; NewNode->next = NULL;  return Head; }
	prohod = Head;
	prohodPrev = NewNode;
	while (true) {
		if (prohod->next
			== NULL) {
			prohod->next = NewNode;
			NewNode->next = NULL;
			break;
		}
		if (strcmp(prohod->next->name,//Значение больше нуля указывает на то, что строка string1 больше строки string2
			prohod->name) <= 0) {
			NewNode->next = prohod;
			prohod->next = NewNode;
			//if (prohodPrev != NULL)prohodPrev->next = NewNode;
			//else Head = NewNode;
			break;
		}
		else {
			prohodPrev = prohod;
			prohod = prohod->next;

			if (prohod->next
				== NULL) {
				prohod->next = NewNode;
				NewNode->next = NULL;
				break;
			}

			continue;
		}
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


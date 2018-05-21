// Stepa.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct list {
	list *next, *prev;
	char str[20];
} List;

int main()
{
	setlocale(LC_ALL, "RUS");
	FILE *file;
	char str[100];
	if (file = fopen("words.txt", "rt"));
	else perror("Error");
	/*HELLO*/
	printf("Программа прочитает файл words.txt,\n");
	printf("Найдет в нем слова полиндромы и удалит их.\n\n");
	printf("\t\tТекст\n\n");
	/*INIT LIST*/
	List *head, *tail, *point;
	head = new List;
	head->next = nullptr;
	head->prev = nullptr;
	strcpy(head->str, "");
	tail = head;
	point = new List;
	point->next = nullptr;
	point->prev = tail;
	tail->next = point;
	tail = point;
	int i, j=0;
	while (fgets(str, 100, file)) {//WRITE OF FILE
		printf("%s", str);
		/*LIST*/
		for (i = 0; i < strlen(str); i++) {
			if ((str[i] == ' ' || str[i] == '\n') && (str[i-1] != ' ')) {
				if (!feof(file)) {
					point->str[j] = '\0'; //'\0' - конец строки
					point = new List;
					point->next = nullptr;
					point->prev = tail;
					tail->next = point;
					tail = point;
					j = 0;
				}
			}
			else {
				/*RECORD*/
				point->str[j++]=str[i];
			}
		}
	}
	fclose(file);
	/*OUTPUT LIST*/
	printf("before:\n");
	point = head;
	while (point->next) {
		printf("%s ", point->str);
		point = point->next;
	}
	/*SEARCH AND DELETE POLINDROME*/
	int flag;
	point = head->next;
	while (point->next) {
		flag = 1;
		for (i = 0; i < strlen(point->str)/2; i++) {
			if (point->str[i] == point->str[strlen(point->str)-1- i]);
			else flag = 0;
		}
		if (flag) {  
			tail = point;
			point->prev->next = point->next;
			point->next->prev = point->prev;
			point = point->next;
			delete tail;
		} else point = point->next;
	}
	/*OUTPUT LIST*/
	printf("\n\nAfter:\n");
	point = head;
	while (point->next) {
		printf("%s ", point->str);
		point = point->next;
	}
	/*CLEAR LIST*/
	point = tail = head;
	while (point) {
		point = tail->next;
		delete tail;
		tail = point;
	}
	head = nullptr;
	/*THE END*/

	return 0;
}


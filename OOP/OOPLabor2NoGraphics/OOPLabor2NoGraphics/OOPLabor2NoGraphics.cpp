// OOPLabor2NoGraphics.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
/*
Лабораторная работа №2
Темы: знакомство с классами в C++
1. Реализовать класс Меню, который запрашивает выбор пользователя и выполняет
соответствующие действия.
2. Пусть Меню является интерфейсом для некоего текстового терминала, который позволяет
вводить слова и добавляет их в общий текст.
3. Терминал должен быть реализован в виде класса, имеющего следующие методы:
Метод		Описание
Открыть
			файл Получает текст для терминала из файла
Ввести
строку
			Пользователь вводит строку, которая добавляется к
			текущему тексту
Показать
текст
			Показывает весь текст, который хранит терминал
Поиск слова Поиск слова во всем тексте
Удаление
слова
Удаление всех случаев встречи слова из текста
Очистить
терминал
Очищает текст, хранимый терминалом
Сохранить
файл
Сохраняет изменения в открытый ранее файл или создает
новый файл с заданным именем
4. В работе рекомендуется использовать класс string:
#include <string>
*/

//#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdio> 
#include <stdio.h>
#include <string.h>

using namespace std;
FILE *tf, *tf1; int n = 1;

class terminal {
private:
	char buffer[100], stringer[100], non[100] = { 0 };
	char key;
public:


	void setstring() {
		tf = fopen("dat.txt", "a");
		gets(buffer);
		fputs(buffer, tf);
		rewind(tf);
		fclose(tf); return;

	}

	void gettext() {

		tf = fopen("dat.txt", "r+");
		while (fgets(buffer, 100, tf)) {

			puts(buffer);
		}
		rewind(tf);
		fclose(tf);
		system("PAUSE");
		return;

	}


	//void seachword() {
	//	cout << "You:  ";

	//	fgets(stringer, 100, stdin);
	//	if (stringer == "как дела?" || stringer == "что делаешь?" || stringer == 'чем занята?') { // вопрсы истинного пикапера
	//		tf = fopen("interst.txt", "r+");
	//		fgets(buffer, 100, tf);
	//		if (feof(tf)) rewind(tf);
	//	}
	//	else if (stringer == 'какая погода?' || stringer == 'что с погодой?') {
	//		tf1 = fopen("weather.txt", "r+");
	//		fgets(buffer, 100, tf1);
	//		if (feof(tf1)) rewind(tf1);
	//	}
	//	else if (stringer == 'кто ты?' || stringer == 'кто тебя создал') {
	//		tf2 = fopen("bot.txt", "r+");
	//		do {
	//			fgets(buffer, 100, tf2);
	//		} while (!feof(tf2)); rewind(tf2);
	//	}
	//	else if (stringer == 'что ты любишь?') {
	//		tf1 = fopen("weather.txt", "r+");
	//		fgets(buffer, 100, tf1);
	//		if (feof(tf1)) rewind(tf1);
	//	}

	//	int i = 0;
	//	tf = fopen("dat.txt", "r");
	//	while (fgets(buffer, 100, tf)) {

	//		if (strcmp(stringer, buffer) == 0) {
	//			i++;
	//			cout << "Mitcu : " << endl;
	//		}
	//		else {
	//			i++;
	//			cout << "Mitcu : I don`t understand you " << endl;
	//		}

	//	}rewind(tf); fclose(tf); system("PAUSE");
	//	//return;

	//}

};
class menu {
private:
	int c;
public:
	terminal a;

	void mamain() {

		while (true) {
			system("cls");
			cout << "Hi this is Chatbot Mitcu! what do you need, friend? :) " << endl;
			cout << "  1 - Start chaating with Mitcu! \n";


			cout << "  0 - Exit ! \n";
			cout << "Your choise  : ";

			switch (_getch()) {
			case '1':system("cls"); a.seachword(); break;
			case '0':return;
			default: puts(" err");
			}
		}

	}

};
int main() {

	menu b;
	b.mamain();
	return 0;
}

#include "stdafx.h"


#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>//  for cout(for C++ only)
using namespace std;// for cout(for C++ only)
/*В новый файл переписать каждую  строку наоборот*/

void clear_file(const std::string& file_name)
{
	std::fstream(file_name, std::fstream::out);
}


int main()
{
	int n;
	char ch;
	char text[200];
	//char text2[200] = "human";

	FILE *txtF, *nbr;                      // Указатели на файлы

	txtF = fopen("текст.txt", "w");  // Создание нового файла текст.txt
	nbr = fopen("наоборот.txt", "r+");

	clear_file("наоборот.txt");//чищу файл перед работой
	fclose(nbr);
	nbr = fopen("наоборот.txt", "w");

	system("CLS");

	//fprintf(txtF, "%s\n", text);
	//fprintf(txtF, "%s\n", text2);
	//fclose(txtF);
	printf("Vvedite chislo strok ");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		printf("\nVvedite tekst novoi stroki na latinice \n");
		cin >> text;
		fprintf(txtF, "%s\n", text);
	}
	fclose(txtF);
	txtF = fopen("текст.txt", "r");
	

	while (!feof(txtF))                  // Пока не конец файла
	{
		char ch = 'G';
		for (; n > 0; n--)
		{
			ch = getc(txtF);//символ переноса строки заменяю следующим чаром
			int i, cnt;
			char a[300];

			for (i = 0; ch != '\n'; i++)
			{
				
				a[i] = ch;
				ch = getc(txtF);
			}
			
			for (i = i - 1; i >= 0; i--)
			{
				putc(a[i], nbr);
			}putc('\n', nbr);
		}
		ch = getc(txtF);

	}
	fclose(nbr);                           // Закрытие файла pr
	fclose(txtF);

	//char ch, sl[50];
	//char text[] = "one two three four";
	//FILE *pf, *pr;                      // Указатели на файлы
	//pf = fopen("new1.txt", "w");  // Создание нового файла new1.txt
	//system(“CLS”);
	//fprintf(pf, "%s\n", text);        // Запись в файл строки text
	//fclose(pf);                            // Закрытие файла pf  
	//pf = fopen("new1.txt", "r");   // Открытие файла pf для чтения
	//pr = fopen("new2.txt", "w");  // Создание нового файла new2.txt
	//while (!feof(pf))                  // Пока не конец файла
	//{
	//	ch = getc(pf);                      // Чтение символа ch из файла pf
	//	if (ch != ' ')
	//		putc(ch, pr);                    // Запись в файл pr символа ch
	//}
	//fclose(pr);                           // Закрытие файла pr
	//rewind(pf);                          // Возврат указателя на начало файла pf
	//fgets(sl, 50, pf);                     // Чтение из файла pf строки в переменную sl
	//printf("%s\n", sl);                 // Вывод строки sl 
	//pr = fopen("new2.txt", "r");   // Открытие файла pr для чтения
	//while (!feof(pr))                 // Пока не конец файла pr
	//{
	//	ch = getc(pr);                   // Чтение символа из файла pr
	//	putchar(ch);                  // Вывод символа ch 
	//}
	//fclose(pf);                          // Закрытие файлов
	//fclose(pr);
	//getch();
	return 0;
}
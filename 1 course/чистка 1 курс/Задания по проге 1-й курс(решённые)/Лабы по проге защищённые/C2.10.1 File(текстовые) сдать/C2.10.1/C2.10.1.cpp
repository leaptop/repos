#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
//#include <cstdlib>// Это нужно, чтобы не выводилось волнистое подчёркивание fclose is ambiguous
#include <string.h>
#include <iostream>//  for cout(for C++ only)
using namespace std;// for cout(for C++ only)
/*Создать текстовый файл из  N строк. Все слова, начинающиеся с гласных,
переписать в один новый файл, а с согласных – в другой новый файл.*/

int main()
{
	int n;
	char ch=' ';
	char text[200];
	text[0] = 'a'; 
	/*Без этого cin.getline(text , 200); не сработает 
				   при первом проходе */
	//string text = "";
	//char text2[] = "a human being is incredible";
	printf("Vvedite chislo strok ");
	cin >> n;
	FILE *txtF, *gl, *sgl;                      // Указатели на файлы
	txtF = fopen("текст.txt", "w");  // Создание нового файла текст.txt
	
	cin.getline(text, 200);//Первый вызов почему-то не срабатывает в цикле. Поэтому вынес его сюда.
	for (int i = 0; i < n; i++)
	{
		printf("\nVvedite tekst novoi stroki na latinice \n");
		cin.getline(text , 200);
		/*while (ch != '\n') {
			int k = 0;
			ch = getc(txtF);
			text[k] = ch;
			k++;
		}*/
		//getline(cin, text);
		
		fprintf(txtF, "%s\n", text);
	}
	fclose(txtF);

	gl = fopen("гласные.txt", "w");
	txtF = fopen("текст.txt", "r");
	sgl = fopen("согласные.txt", "w");

	while (!feof(txtF))                  // Пока не конец файла
	{
		ch = getc(txtF);                      // Чтение символа ch из файла pf
		if (ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' || ch == 'a')
		{
			while (ch != ' '&&ch != '\n') {
				putc(ch, gl);                    // Запись в файл pr символа ch
				ch = getc(txtF);
			}
			putc(' ', gl);
		}
		else if (ch == 'b' || ch == 'c' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h'
			|| ch == 'j' || ch == 'k' || ch == 'l' || ch == 'm' || ch == 'n' || ch == 'p'
			|| ch == 'q' || ch == 'r' || ch == 's' || ch == 't' || ch == 'v' || ch == 'w'
			|| ch == 'bx' || ch == 'z')
		{
			while (ch != ' '&&ch != '\n') {
				putc(ch, sgl);                    // Запись в файл pr символа ch
				ch = getc(txtF);
			}
			putc(' ', sgl);
		}
	}
	fclose(gl);                           // Закрытие файла pr
	fclose(txtF);
	fclose(sgl);

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
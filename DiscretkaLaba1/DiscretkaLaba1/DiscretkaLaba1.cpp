// DiscretkaLaba1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#pragma warning(disable : 4996)


using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, i, c;
	cout << "number of elements А=";
	scanf("%d", &a);
	cout << "number of elements B=";
	scanf("%d", &b);
	char A[a], B[b], C[b], M[a], P[a];
L:
	system("cls");
	cout << "А: ";
	for (i = 0; i<a * 2; i++)
	{
		scanf("%c", &A[i]);

	}
	for (i = 0; i<a * 2; i++) { if ((A[i] == '1') || (A[i] == '2') || (A[i] == '3') || (A[i] == '4') || (A[i] == '5') || (A[i] == '6') || (A[i] == '7') || (A[i] == '8') || (A[i] == '9') || (A[i] == '0') || (A[i] == '!') || (A[i] == '@') || (A[i] == '#') || (A[i] == '$') || (A[i] == '%') || (A[i] == '^') || (A[i] == '&') || (A[i] == '*') || (A[i] == '(') || (A[i] == ')') || (A[i] == '"') || (A[i] == '№') || (A[i] == ';') || (A[i] == ':') || (A[i] == '?') || (A[i] == '`') || (A[i] == '~') || (A[i] == '-') || (A[i] == '_') || (A[i] == '+') || (A[i] == '=') || (A[i] == '[') || (A[i] == ']') || (A[i] == '{') || (A[i] == '}') || (A[i] == '/') || (A[i] == '|') || (A[i] == '.') || (A[i] == '>') || (A[i] == ',') || (A[i] == '<') || (A[i] == 'а') || (A[i] == 'б') || (A[i] == 'в') || (A[i] == 'г') || (A[i] == 'д') || (A[i] == 'е') || (A[i] == 'ё') || (A[i] == 'ж') || (A[i] == 'з') || (A[i] == 'и') || (A[i] == 'й') || (A[i] == 'к') || (A[i] == 'л') || (A[i] == 'м') || (A[i] == 'н') || (A[i] == 'о') || (A[i] == 'п') || (A[i] == 'р') || (A[i] == 'с') || (A[i] == 'т') || (A[i] == 'у') || (A[i] == 'ф') || (A[i] == 'х') || (A[i] == 'ц') || (A[i] == 'ч') || (A[i] == 'ш') || (A[i] == 'щ') || (A[i] == 'ъ') || (A[i] == 'ы') || (A[i] == 'ь') || (A[i] == 'э') || (A[i] == 'ю') || (A[i] == 'я')) { goto L; } }


	for (i = 0; i<a * 2; i++)
	{
		M[i] = A[i];
	}

	puts("\n");
K:
	cout << "B: ";
	for (i = 0; i<b * 2; i++)
	{
		scanf("%c", &B[i]);
	}
	for (i = 0; i<b * 2; i++)
	{
		C[i] = B[i];
	}
	for (i = 0; i<a * 2; i++) { if ((B[i] == '1') || (B[i] == '2') || (B[i] == '3') || (B[i] == '4') || (B[i] == '5') || (B[i] == '6') || (B[i] == '7') || (B[i] == '8') || (B[i] == '9') || (B[i] == '0') || (B[i] == '!') || (B[i] == '@') || (B[i] == '#') || (B[i] == '$') || (B[i] == '%') || (B[i] == '^') || (B[i] == '&') || (B[i] == '*') || (B[i] == '(') || (B[i] == ')') || (B[i] == '"') || (B[i] == '№') || (B[i] == ';') || (B[i] == ':') || (B[i] == '?') || (B[i] == '`') || (B[i] == '~') || (B[i] == '-') || (B[i] == '_') || (B[i] == '+') || (B[i] == '=') || (B[i] == '[') || (B[i] == ']') || (B[i] == '{') || (B[i] == '}') || (B[i] == '/') || (B[i] == '|') || (B[i] == '.') || (B[i] == '>') || (B[i] == ',') || (B[i] == '<') || (B[i] == 'а') || (B[i] == 'б') || (B[i] == 'в') || (B[i] == 'г') || (B[i] == 'д') || (B[i] == 'е') || (B[i] == 'ё') || (B[i] == 'ж') || (B[i] == 'з') || (B[i] == 'и') || (B[i] == 'й') || (B[i] == 'к') || (B[i] == 'л') || (B[i] == 'м') || (B[i] == 'н') || (B[i] == 'о') || (B[i] == 'п') || (B[i] == 'р') || (B[i] == 'с') || (B[i] == 'т') || (B[i] == 'у') || (B[i] == 'ф') || (B[i] == 'х') || (B[i] == 'ц') || (B[i] == 'ч') || (B[i] == 'ш') || (B[i] == 'щ') || (B[i] == 'ъ') || (B[i] == 'ы') || (B[i] == 'ь') || (B[i] == 'э') || (B[i] == 'ю') || (B[i] == 'я')) { goto K; } }
	puts("\n");
M:
	puts("\n");
	cout << "1. show sets А и B" << endl;
	cout << "2. А U B" << endl;
	cout << "3. intersection А and В" << endl;
	cout << "4. A without B" << endl;
	cout << "5. B without А" << endl;
	cout << "6. Symmetric difference А and В" << endl;
	cout << "0. Out" << endl;

	int p, j, k;
	char t;

	p = getch();
	switch (p)
	{
	case '1': system("cls");
		cout << "А: "; for (i = 1; i<a * 2; i++) { printf("%c", M[i]); }
		puts("\n");
		cout << "В: "; for (i = 1; i<b * 2; i++) { printf("%c", C[i]); }
		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;
	case '2': system("cls");
		for (i = 1; i<a * 2; i++) { A[i] = M[i]; }
		for (i = 1; i<b * 2; i++) { B[i] = C[i]; }
		for (i = 0; i<a * 2; i++)
		{
			t = A[i];
			for (j = b * 2; j>0; j--)
			{
				if (A[i] == B[j]) B[j] = 0;

			}
		}

		for (i = 1; i<a * 2; i += 2) { printf("%c", A[i]); cout << " "; }
		for (i = 1; i<b * 2; i += 2) { if (B[i] != 0) printf("%c", B[i]); cout << " "; }
		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;
	case '3': system("cls");
		for (i = 1; i<a * 2; i++) { A[i] = M[i]; }
		for (i = 1; i<b * 2; i++) { B[i] = C[i]; }
		for (i = 0; i<a * 2; i++)
		{
			t = A[i];
			for (j = b * 2; j>0; j--)
			{
				if (A[i] == B[j]) P[j] = A[i];

			}
		}

		for (i = 1; i<((a * 2)) - 1; i++) { printf("%c", P[i]); cout << " "; }

		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;
	case '4': system("cls");
		for (i = 1; i<a * 2; i++) { A[i] = M[i]; }
		for (i = 1; i<b * 2; i++) { B[i] = C[i]; }
		for (i = 0; i<a * 2; i++)
		{
			t = A[i];
			for (j = b * 2; j>0; j--)
			{
				if (A[i] == B[j]) A[i] = 0;

			}
		}

		for (i = 1; i<a * 2; i++) { printf("%c", A[i]); cout << " "; }
		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;
	case '5':system("cls");
		for (i = 1; i<a * 2; i++) { A[i] = M[i]; }
		for (i = 1; i<b * 2; i++) { B[i] = C[i]; }
		for (i = 0; i<a * 2; i++)
		{
			t = A[i];
			for (j = b * 2; j>0; j--)
			{
				if (A[i] == B[j]) B[i] = 0;

			}
		}

		for (i = 0; i<b * 2; i++) { printf("%c", B[i]); cout << " "; }
		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;
	case '6': system("cls");
		for (i = 1; i<a * 2; i++) { A[i] = M[i]; }
		for (i = 1; i<b * 2; i++) { B[i] = C[i]; }
		for (i = 0; i<a * 2; i++)
		{
			t = A[i];
			for (j = b * 2; j>0; j--)
			{
				if (A[i] == B[j]) { A[i] = 0; B[j] = 0; }

			}
		}

		for (i = 1; i<a * 2; i += 2) { printf("%c", A[i]); cout << " "; }
		for (i = 1; i<b * 2; i++) { printf("%c", B[i]); }

		puts("\n");
		cout << "0. Return to menu";
		c = getch();
		if (c == '0') system("cls"); goto M;

	case '0': break;
	default: system("cls"); cout << "Error"; goto M;


	}


	system("PAUSE");
}




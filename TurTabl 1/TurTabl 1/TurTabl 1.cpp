// TurTabl 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct team
{
	char name[32];
	int point;
};

const int NUM_TEAM = 8;
team t[NUM_TEAM];

void AddPoint(char* name, int p1, int p2);

int main()
{
	ifstream inFootbal("foot.txt");
	ifstream inTeam("team.txt");
	char ch;
	char foratoi[2];
	char name[32];
	int i = 0, j = 0;

	int p1, p2;
	bool b1 = true, b2 = true;

	if (!inFootbal.is_open())
	{
		cout << "ERROR!!!";
		exit(1);
	}
	if (!inTeam.is_open())
	{
		cout << "ERROR!!!";
		exit(1);
	}

	while (inTeam)
	{
		inTeam.get(ch);
		if (inTeam)
		{
			if (ch == '\n')continue; //ВОТ ЗДЕСЬ ПОПРАВИЛ,ТЕПЕРЬ ВСЕ РАБОТАЕТ
			if (ch != ' ')
			{
				t[j].name = ch;
				i++;
			}
			else
			{
				t[j].name = '\0';
				i = 0;
				j++;
			}
		}
		t[j].point = 0;
	}
	t[j].name = '\0';

	i = 0;
	j = 0;
	while (inFootbal)
	{
		inFootbal.get(ch);

		if (inFootbal)
		{
			if (ch != ' ' && b2)
			{
				name = ch;
				i++;
			}
			else if (ch == ' ')
			{
				name = '\0';
				b2 = false;
			}
			else if ((ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0'))
			{
				if (b1)
				{
					foratoi[1] = '\0';
					foratoi[0] = ch;
					p1 = atoi(foratoi);
					b1 = false;
				}
				else
				{
					foratoi[1] = '\0';
					foratoi[0] = ch;
					p2 = atoi(foratoi);
					i = 0;
					j++;
					AddPoint(name, p1, p2);
					b1 = true;
					b2 = true;
				}
			}
		}

	}
	for (i = 0; i<NUM_TEAM; i++)
	{
		cout << t.name << ' ' << t.point << endl;
	}
	return 0;
}

void AddPoint(char* name, int p1, int p2)
{
	int i;
	for (i = 0; i<NUM_TEAM; i++)
	{
		if (!strcmp(t.name, name))
		{
			if (p1>p2)t.point += 3;
			else if (p1 == p2)t.point += 2;
			else if (p1<p2)t.point += 1;
			break;
		}
	}
}
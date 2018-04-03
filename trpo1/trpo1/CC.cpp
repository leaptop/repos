#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


void ClearChess()
{
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|8|| R | N | B | Q | K | B | N | R |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|7|| P | P | P | P | P | P | P | P |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|6||   |   |   |   |   |   |   |   |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|5||   |   |   |   |   |   |   |   |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|4||   |   |   |   |   |   |   |   |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|3||   |   |   |   |   |   |   |   |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|2|| p | p | p | p | p | p | p | p |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("|1|| r | n | b | k | q | b | n | r |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
    printf("| || a | b | c | d | e | f | g | h |\n");
    printf("+-++---+---+---+---+---+---+---+---+\n");
	
    return;
};

void Chess(char Q[][8])
{     int j, i;
for(j=0;j<8;j++)
{
	printf("+-++---+---+---+---+---+---+---+---+\n");
	printf("|%d||",8-j);
	for(i=0;i<8;i++)
	{
		printf(" ");
		printf("%c",Q[j][i]);
		printf(" |");
	}
	printf("\n");
}
printf("+-++---+---+---+---+---+---+---+---+\n");
}

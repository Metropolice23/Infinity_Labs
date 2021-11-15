#include <stdio.h>
#include "array_pointers.h"

int main()
{

	/************************************************/
	/***********************Sum**********************/
	/************************************************/

	printf ("------------------------SumMtx Test-------------------------\n");

	int row = 10;
	int col = 14;
	int mtx[row][col];
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
		{
			mtx[i][j] = 10;
		}
	}
	
	for (int i = 0; i < row; i++)
	{
		mtx[2][i] = 3;
	}
	mtx[9][9] = 670;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
		{
			printf("%d  ", mtx[i][j]);
		}
		printf("\n");
	}
	
	int sumarr[row];
	MtxSum (row, col, mtx, sumarr);
	for (int j = 0; j < row; j++) 
		{
			printf("****%d  ", sumarr[j]);
		}
		printf("\n");
	
	
	/************************************************/
	/*******************Josephus*********************/
	/************************************************/
	
	printf ("------------------------Josephus Test-------------------------\n");
	
	int check = Lucky(14);
	printf("\nfor check = 14 - result should be 13\n");
	printf("result - %d\n", check);
	
	printf ("\n----------------\n");
	    
	check = Lucky(430);
	printf("\nfor check = 430 - result should be 349\n");
	printf("result - %d\n", check);
	
	printf ("\n----------------\n");
	
	check = Lucky(142);
	printf("\nfor check = 142 - result should be 29\n");
	printf("result - %d\n", check);
	
	
}

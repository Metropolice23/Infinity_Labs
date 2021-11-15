#include <stdio.h>
#include <string.h>
#include "array.h"

int Lucky(int num)
{
	int sword = 0;
	int people = num;
	int arr[num];
	
	for (int i=0; i<num; i++)
	{
		arr[i] = 1;
	}
	
	while (people > 1)
	{
		for (int i=0; i<num; i++)
		{
			if (arr[i] == 1 && sword == 0)
			{
				sword = 1;
			}
			else if (arr[i] == 1 && sword == 1)
			{
				sword = 0;
				arr[i] = 0;
				people--;
			}
		}
	}
	for (int i=0; i<num; i++)
	{
		if (arr[i] == 1)
		{
			return ++i;
		}
	}
}

int MtxSum(int row, int col, const int matrix [row][col], int arr[row])
{
	int sum = 0;
	
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) 
			{
				sum += matrix[i][j];
			}
			arr[i] = sum;
			sum = 0;
		}
		return 0;
}












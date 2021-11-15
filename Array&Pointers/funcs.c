#include <stdio.h>
#include "array_pointers.h"

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

int DTypeNames()
{
	char dtypes[8][10] = {{"char"}, {"short"}, {"int"}, {"unsigned"}, {"long"}, {"long long"}, {"float"}, {"double"}};
	size_t sizes[8] = {sizeof(char), sizeof(short), sizeof(int), sizeof(unsigned), sizeof(long), sizeof(long long), 						sizeof(float), sizeof(double)};
	
	for(int i=0; i<8; i++)
	{
		printf("The size of type ");
		for(int j=0; j<9; j++)
		{
			printf("%c", dtypes[i][j]);
		}
		printf(" is %lu\n", sizes[i]);
	}
}












#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		printf("The size of type  ");
		for(int j=0; j<9; j++)
		{
			printf("%c", dtypes[i][j]);
		}
		printf("is %lu\n", sizes[i]);
	}
}

extern char **environ;
int PrintEnv()
{   
	int i = 0;
    int j = 0;
    int size = 0;
    char char_temp;
    char **temp;
    
    char **env = environ;
    for (temp = env; *temp; temp++)
    {
        size++;
    }   

    char **arr = (char**)malloc(sizeof(char*)*(size));
  
    if (NULL == arr)
    {
        printf("ERROR arr memory allocation\n");
        exit(0);
    }
    else
    {
    	while(env[j])
    	{
			arr[j] = (char *) malloc((strlen(env[j])+1)*sizeof(char));
			if (NULL == arr[j])
			{
 	           printf("ERROR arr[%d] memory allocation\n", j);
	            exit(0);
			}
    	    else
			{
				while( i < strlen(env[j]))
    	        {
    	            char_temp = tolower(env[j][i]);
    	            arr[j][i] = char_temp;
    	            i++;
    	        }
    	        
				arr[j][i] = '\0';       
				i = 0;
				j++;
			}     
		}
    	j = 0;	    
		while(j < size)
		{   
			printf("%s\n", arr[j]);
			free(arr[j]);
			arr[j] = NULL;
			j++;
		}
		free(arr);
		arr = NULL;
	}
}	


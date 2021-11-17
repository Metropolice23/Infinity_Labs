#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

struct print_me
{
	int num;
	void (*ptr)(int num2);	
};

int main()
{
	/************************************************/
	/***********************Ex1**********************/
	/************************************************/

	printf ("------------------------Ex1 Test-------------------------\n");

	struct print_me arr1[10];

	for(int i=0; i<10; i++)
	{
		arr1[i].num = i;
		arr1[i].ptr = Print;
		arr1[i].ptr(arr1[i].num);
	}	

	printf ("\n---------------------------\n");

	/************************************************/
	/**********************Ex2***********************/
	/************************************************/

	printf ("------------------------Ex2p1 Test-------------------------\n");
	char input[100];
	FILE * fn;
	int check = 0;
	int cnt = 0;
	char fileName[100];


	while (check < 2)
	{
		printf("Enter file name: ");
		scanf("%s", fileName);
		check += Openf(&fn, fileName);

		while (cnt == 0)
		{
		printf("Enter string: ");
		scanf(" %[^\n]",input);
		if (Logger(fn, fileName, input) == 0)
			{
				Writef(&fn, str);
			}
		}
	}
	check = 0;

	return 0;
}

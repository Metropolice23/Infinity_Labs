#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phase1.h"
#include "phase2.h"

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
	char fileName[100];

	printf("Enter file name: ");
	scanf("%s", fileName);
	Logger(fileName);

}

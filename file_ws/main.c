#include <stdio.h>
#include <stdlib.h>
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

	struct print_me arr[10];

	for(int i=0; i<10; i++)
	{
		arr[i].num = i;
		arr[i].ptr = Print;
		arr[i].ptr(arr[i].num);
	}	

	printf ("\n---------------------------\n");

	/************************************************/
	/***********************Ex2**********************/
	/************************************************/

	printf ("------------------------Ex2 Test-------------------------\n");
	char c;
	printf("Enter file name: ");
	char fileName[100];
	scanf("%s", fileName);
	FILE * fn;
	fn = fopen(fileName, "r"); 

	while((c=fgetc(fn))!=EOF)
	{
		printf("%c",c);
	}
    fclose(fn);

	//const char *text = "Write this to the file";
	//fprintf(f, "Some text: %s\n", text);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "phase1.h"
#include "phase2.h"

#define MAX_L 100

void Print(int num)
{
	printf("%d\n", num);
}

int Openf(FILE * fp, char * filename)
{
	if( access( filename, F_OK ) == 0 )
	{
    	fp = fopen(filename, "a+");
		return 1;
	}
	else
  	{
    	printf("Error - file doesn't exist\n");
		return 0;
	}
}

int Closef(FILE * fp, char * filename)
{
	if( access( filename, F_OK ) == 0 )
	{
    	fclose(fp);
		return 1;
	}
	else
  	{
    	printf("Error - file doesn't exist\n");
		return 0;
	}
}

exitstatus_t Writef(FILE * fp, char* filename, char* string)
{
	fp = fopen(filename, "a+");
	//fprintf(fp, "%s\n", string);
	fputs(string,fp);
	fputc('\n',fp);
	fclose (fp);
	return WRITE;
}

exitstatus_t RemoveFile(FILE *fp, char* filename, char* string)
{
	remove(filename);
	return REMOVE;
}

exitstatus_t CountLines(FILE *fp, char* filename, char* string)
{
	fp = fopen(filename, "a+");
	char c;
	int ctr =0 ;
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			ctr++;
		}
	}
	printf("The file %s has %d lines", filename, ctr);
	fclose(fp);
	return COUNTLINE;
}

exitstatus_t ExitFile(FILE *fp, char* filename, char* string)
{
	exit (0);
	return EXIT;
}

exitstatus_t SetStart(FILE *fp, char* filename, char* string )
{
	char temp[1000];
	char c;
	int j = 0;
	fp = fopen(filename, "r");
	for (c = fgetc(fp); c != EOF; c = fgetc(fp))
	{
		temp[j] = c;
		j++;
	}
	temp[j] = '\0';
	fclose(fp);
	fp = fopen(filename, "w");
	string++;
	fputs (string, fp);
	fputs ("\n", fp);
	fputs (temp, fp);
	fclose(fp);
	return APPEND;
}

int CompareFirst(char* string, char* string2)
{
	if (string[0] == string2[0])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Compare(char* string, char* string2)
{
	if (strcmp(string, string2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Compn(char* string, char* string2)
{
	return 1;
}

int Logger(char *filename)
{
	FILE * fp;
	char input[MAX_L];

	struct Logaction arr[5];
	
		arr[0].string = "-remove";
		arr[0].cmp = Compare;
		arr[0].opt = RemoveFile;

		arr[1].string = "-count";
		arr[1].cmp = Compare;
		arr[1].opt = CountLines;

		arr[2].string = "-exit";
		arr[2].cmp = Compare;
		arr[2].opt = ExitFile;

		arr[3].string = "<";
		arr[3].cmp = CompareFirst;
		arr[3].opt = SetStart;

		arr[4].string = "write";
		arr[4].cmp = Compn;
		arr[4].opt = Writef;

	while (1)
	{
		printf("\nEnter string: ");
		scanf("%s", input);

		for(int i = 0; i < 5; i++)
		{
			if(arr[i].cmp(arr[i].string, input) == 1)
			{
				arr[i].opt(fp, filename, input);
				break;
			}
		}
		// if(arr[3].cmp(input, arr[3].string))
		// {
		// 	check = arr[3].opt(fp, filename, input);
		// }
	//	printf("BINGO");
	}
}



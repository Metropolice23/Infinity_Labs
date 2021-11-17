#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file.h"


void Print(int num)
{
	printf("%d\n", num);
}

int Openf(FILE ** fn, char fileName[])
{
		if( access( fileName, F_OK ) == 0 )
		{
    		*fn = fopen(fileName, "a+");
			return 1;
		}
		else
  		{
    		printf("Error - file doesn't exist\n");
			return 0;
		}
}

int Closef(FILE ** fn, char fileName[])
{
		if( access( fileName, F_OK ) == 0 )
		{
    		fclose(*fn);
			return 1;
		}
		else
  		{
    		printf("Error - file doesn't exist\n");
			return 0;
		}
}

int Writef(FILE ** fn, char str[])
{
	printf("Enter string: ");
	scanf(" %[^\n]",str);
	fprintf(*fn, "%s\n", str);
	return 1;
}

int RemoveFile(FILE *fp, char* FileName)
{
	Closef(&fp, FileName)
	remove(FileName);
	return 1;
}
int CountLines(FILE *fp, char* FileName)
{
	char c;
	int ctr =0 ;
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			ctr++;
		}
	}
	printf("The file %s has %d lines", FileName, ctr);

}
int ExitFile(FILE *fp, char* FileName)
{
	return Closef(&fp, fileName);
}
int SetStart(FILE *fp, char* FileName, char* string )
{
	
}

int CompareFirst(char* string, char* string2)
{
	if (string[0] == "<")
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
	if (strcmp(string, string2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Logger(FILE* f, char *file_name, char *str1 ... )
{
	struct two_func logger[4];
	
	logger[0].string = "-remove";
	logger[0].cmp = Compare;
	logger[0].opt = RemoveFile;

	logger[1].string = "-count";
	logger[1].cmp = Compare;
	logger[1].opt = CountLines;

	logger[2].string = "-exit";
	logger[2].cmp = Compare;
	logger[2].opt = ExitFile;

	logger[3].string = "<";
	logger[3].cmp = CompareFirst;
	logger[3].opt = SetStart;

	for(int i = 0; i < 3; i++)
	{
		if(logger[i].cmp(logger[i].string, str1))
		{
			logger[i].opt(f, file_name, str1);
			return 1;
		}
		if(logger[3].cmp(logger[3].string, str1))
	}
	return 0;
}



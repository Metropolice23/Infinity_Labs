#include <stdio.h>
#include <string.h>
#include "pointers2.h"

//return 1 for palindrome - 0 if not, for given string.
int IsPali(char* str)
{
	const char* end = (str + strlen(str) - 1);
	while (end > str)
	{
		if (*end != *str)
		{
			return 0;
		} 
		end--;
		str++;
	}
	return 1;	
}

//print all numbers in the range "start" - "end". print "BOOM" instead of numbers that devine by 7 with no reminder.
void Boom7 (int start, int end)
{
int temp = 0;
int flag = 1;
	while (start < end)
	{
		flag = 1;
		if ((start % 7) == 0)
		{
			printf("Boom\n");
			flag = 0;
		}
		else
		{
			temp = start;
			while (temp > 0)
			{
			//printf("***%d\n", temp);
				if (temp % 10 == 7)
				{
					printf("Boom\n");
					flag = 0;
					temp = 0;
				}
				else
				{
				temp = temp / 10;
				}
			}
		}
		if (flag)
		{
			printf("%d\n", start);
		}
		start++;
	}
}
//delete all the duplicate space-chars of a given string. Delete space-cahrs in the end/begginning of the strings if exists.
//void DelSpace(char* str);
//{
//}



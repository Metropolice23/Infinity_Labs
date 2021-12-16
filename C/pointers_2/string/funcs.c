#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void ToLower(char *str)
{
    while(*str != '\0')
    {
        if(*str >=65 && *str<=90)
        {
            *str = *str + 32;
        }
        str++;
    }

}

/***********************Ruturn the legnth of a given array*****************************/  
int strLen(const char* str)
 {
 	int ctr = 0;
 	while (*str != '\0')
 	{
 		str++;
 		ctr++;
 	}
 	return ctr;
 } 
/***********************Compare two given arrayes*****************************/  
int strCmp (const char* str1, const char* str2)
{
	while (( *str1 == *str2 ) && ( *str1 != 0) && ( *str2 != 0))
    {
	    str1++;
		str2++;
	}
	return (*str1 - *str2);
}
	
int strnCmp(const char *str1, const char *str2, size_t num)
{
int ctr = 0;
while (( *str1 == *str2 ) && ( *str1 != 0) && ( *str2 != 0) && (ctr < num))
    {
	    str1++;
		str2++;
		ctr++;
	//	printf("%s\n", str1);
	//	printf("%s\n", str2);
	}
	return (*str1 - *str2); 
}

char *strcpy(char *dest, const char *src)
{
	while (*src)
		{
			*dest = *src;
			dest++;
			src++;
		}
	dest = 0;
	return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	for(int i=0; i<n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	dest = 0;
	return (char*) dest;
}

int strcasecmp(const char *string1, const char *string2)
{
	char nsrc[strLen(string1)];
	char ndest[strLen(string2)];
	int j = 0;

	strcpy(nsrc, string1);
	strcpy(ndest, string2);

	for (int i=0; i< strLen(nsrc); i++)
	{
		ToLower(nsrc);
	}
	
	for (int i=0; i< strLen(ndest); i++)
	{
		ToLower(ndest);
	}
	
	return (strCmp(nsrc, ndest));

/*	while (ndest[j] == nsrc[j])
	{
		j++;
	} 
	return (*ndest - *nsrc); */
}

char *strncat(char *dest, const char *src, size_t n)
{
	int num = strLen(dest);
	int i = 0;
	
	while(src[i] != 0 && i < n)
	{
		dest[num+i] = src[i];
		i++;
	}
	dest[num + i] = 0;
	return dest;
}

char *strchr(const char *str, int c)
{
	while (*str != c)
	{
		str++;
	}
	return (char*) str;
}

size_t strspn(const char *str1, const char *str2)
{
	int flag = 0;
	size_t ctr = 0;

	while (*str1)
	{
		for (int i=0; i<strLen(str2); i++)
		{
			if (*str1 == str2[i])
			{
				ctr++;
				flag++;
			}
		}
		str1++;
		if (flag == 0)
		{
			return ctr;
		}
		else
		{
			flag = 0;
		}
	}
	return ctr;
}

char *strstr(const char *haystack, const char *needle)
{
	int flag = 0;
	int haylen = strLen(haystack);
	int needlen =  strLen(needle);

	while (*haystack != '\0')
    {
        if ((*haystack == *needle) && strCmp(haystack, needle))
        {
        	return (char*) haystack;
        }
        haystack++;
    }
 
    return NULL;
}


/*
char *strtok(char *str, const char *delim)
{
}
*/

char *strcat(char *dest, const char *src)
{
	int num1 = strLen(dest);
	int num2 = strLen(src);
	
	for (int i=num1; i<(num1 + num2); i++)
	{
		dest[i] = *src;
		src++;
	}
	dest[num1 + num2 +1] = 0;
	return dest;
}

char * strdup(const char *str1)
{
    char *dest = calloc(strLen(str1) + 1, sizeof(char));
    if (dest == 0)
    { 
    	return NULL;
    }        
    strcpy(dest, str1);
    return dest;
	
}




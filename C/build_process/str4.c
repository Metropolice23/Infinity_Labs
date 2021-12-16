#include "str.h"

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
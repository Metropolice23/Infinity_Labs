#include "str.h"


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
#include <stdio.h>
#include "pointers.h"
/***********************swap two int*****************************/
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/***********************swap two size_t*****************************/
void SwapSize(size_t* x, size_t* y)
{
    size_t temp = *x;
    *x = *y;
    *y = temp;
}
/***********************swap two size_t pointers*****************************/
void SwapSizeP(size_t** c, size_t** d)
{
    size_t* temp = *c;
    *c = *d;
    *d = temp;
}
/***********************swap two size_t pointers by swapSize*****************************/
void SwapSizePc(size_t** cp1, size_t** dp1)
{
   SwapSize ((size_t*)cp1, (size_t*)dp1); 
}
/***********************swap two size_t pointers by swap*****************************/
void SwapSizePd(size_t** cp2, size_t** dp2)
{
   Swap ((int*)cp2, (int*)dp2); 
}
/***********************Copy onw array to another*****************************/
void CopyArray (int *arr1, int* arr2, int leng)
{
   for (int i = 0; i < leng; i++)
    {
      *arr2 = *arr1;
      arr1++;
      arr2++;
    }
}
/***********************Ruturn the legnth of a given array*****************************/  
 int strLen (const char* str)
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
	while (*str1 == *str2 && *str1 != 0 && *str2 != 0)
    {
        printf("%c\t%c\n", *str1, *str2);
	    str1++;
		str2++;
	}
	return (*str1 - *str2);
}
	

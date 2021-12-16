#include <stdio.h>
#include "pointers.h"

int main()
{
	printf ("------------------------ex1-------------------------\n");
	
    int a = 10;
    int b = 20;
    Swap (&a, &b);
    printf ("%d\n%d\n", a, b);
    
    printf ("------------------------ex2-------------------------\n");
    
    int leng = 10;
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int arr2[leng];
    
    CopyArray(arr1, arr2, leng);
    
    for (int i = 0; i < leng; i++)
    {
       printf("%d\n", arr2[i]);
    }
    
    printf ("------------------------ex4a-------------------------\n");
	
    size_t x = 115;
    size_t y = 235;
    SwapSize (&x, &y);
    printf ("%lu\n%lu\n", x, y);
    
    printf ("------------------------ex4b-------------------------\n");
	
    size_t c = 352;
    size_t d = 848;
    
    size_t* cp = &c;
    size_t* dp = &d;
    
    printf ("%p\t%p\n", cp, dp);
    SwapSizeP (&cp, &dp);
    printf ("%p\t%p\n", cp, dp);
    
	printf ("------------------------ex4c-------------------------\n"); 
    
    size_t c1 = 154;
    size_t d1 = 935;
    
    size_t* cp1 = &c1;
    size_t* dp1 = &d1;
    
    printf ("%p\t%p\n", cp1, dp1);
    SwapSizePc (&cp1, &dp1);
    printf ("%p\t%p\n", cp1, dp1);
    
    printf ("------------------------ex4d-------------------------\n"); 
    
    size_t c2 = 110;
    size_t d2 = 745;
    
    size_t* cp2 = &c2;
    size_t* dp2 = &d2;
    
    printf ("%p\t%p\n", cp2, dp2);
    SwapSizePd (&cp2, &dp2);
    printf ("%p\t%p\n", cp2, dp2);
    
    printf ("------------------------ex set 2leng-------------------------\n"); 
    
    const char str1[] = {'u','b','t','n','g','q','\0'};
    
    char str[] = "omrishurkingkong";
    printf ("%d\n", strLen(str));
    
    
    printf ("------------------------ex set 2cmp-------------------------\n");
    
    char str3[] = {'u','b','t','n','g','q','\0'};
    char str4[] = {'u','b','t','n','g','q','\0'};
    int num = strCmp (str3, str4);
    printf("%d", num);
    
return 0;
}

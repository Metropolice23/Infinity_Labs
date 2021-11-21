
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[20];
    char *str2 = malloc(sizeof(*str2) * 20);
    char *str3 = "whatever";
    char str4[] = "whatevermnm";
    str3[1] = 'a';
    
    printf("str 1 - %s\n", str1);
    printf("str 2 - %s\n", str2);
    printf("str 3 - %s\n", str3);
    printf("str 4 - %s\n", str4);
    
   // printf("size of str 1 - %lu\n", sizeof(str1));
  //  printf("size of str 2 - %lu\n", sizeof(str2));
  //  printf("size of str 3 - %lu\n", sizeof(str3));
   // printf("size of str 4 - %lu\n", sizeof(str4));
                

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


    /**************************************************************/
    /*********************** Stack-Test ***************************/
    /**************************************************************/

int main ()
{
    printf("\n$$$$$$$---Stack Test---$$$$$$$\n");

    /*********************** Create-Test ***************************/
    printf("\n-------------Create Test---------------\n");

    size_t cap1 = 10;
    size_t cap2 = 20;
    size_t cap3 = 30;
    size_t cap4 = 40;
    void* s4 = NULL;
   
    void* s1 = StackCreate(cap1);
    void* s2 = StackCreate(cap2);
    void* s3 = StackCreate(cap3);
    s4 = StackCreate(cap4);
    printf("shuold be - \nNOT NULL");
    printf("\nresult is - \n");
    printf("%p\n", s4);
    

    /*********************** Destroy-Test **************************/
    printf("\n-------------Destroy Test---------------\n");

    StackDestroy(s4);
    s4 = NULL;
    printf("shuold be - \nNULL");
    printf("\nresult is - \n");
    printf("%p\n", s4);

    /*********************** Push-Test ******************************/
    printf("\n-------------Push Test---------------\n");

    int num1 = 34;
    int num2 = 890;
    char *str1 = "omri";
    char str2 = 'Q';
    StackPush(s1, &num1);
    StackPush(s1, str1);
    StackPush(s1, &num2);
    StackPush(s1, &str2);

    /*********************** Pop-Test *****************************/
    printf("\n-------------Pop Test---------------\n");

    printf("shuold be - \n");
    printf("Q\t890\tomri\t34");
    printf("\nresult is - \n");
    printf("%c\t", *(char*)StackPop(s1));
    printf("%d\t", *(int*)StackPop(s1));
    printf("%s\t", (char*)StackPop(s1));
    printf("%d\t", *(int*)StackPop(s1));
  
    /*********************** Peek-Test *****************************/
    printf("\n-------------Peek Test---------------\n");

    StackPush(s1, &num1);
    StackPush(s1, &str2);
    StackPush(s1, &num2);
    StackPush(s1, str1);
    printf("shuold be - \nomri");
    printf("\nresult is - \n");
    printf("%s\n", (char*)StackPeek(s1));

    /*********************** Size-Test *****************************/
    printf("\n-------------Size Test---------------\n");
    for(int i=0; i<7; i++)
    {
        StackPush(s2, &num1);
    }
    printf("shuold be - \n");
    printf("7");
    printf("\nresult is - \n");
    printf("%ld\n", StackSize(s2));

    /*********************** IsEmpty-Test **************************/
    printf("\n-------------IsEmpty Test---------------\n");

    printf("shuold be - \n");
    printf("TRUE");
    printf("\nresult is - \n");
    printf("%d\n", IsStackEmpty(s3));
    printf("\n----------------------------\n");
    printf("shuold be - \n");
    printf("FALSE");
    printf("\nresult is - \n");
    printf("%d\n", IsStackEmpty(s2));


    /*********************** Capacity-Test *************************/
    printf("\n-------------Capacity Test---------------\n");

    printf("shuold be - \n");
    printf("10");
    printf("\nresult is - \n");
    printf("%ld\n", StackCapacity(s1));
    printf("\n----------------------------\n");
    printf("shuold be - \n");
    printf("20");
    printf("\nresult is - \n");
    printf("%ld\n", StackCapacity(s2));
    printf("\n----------------------------\n");
    printf("shuold be - \n");
    printf("30");
    printf("\nresult is - \n");
    printf("%ld\n", StackCapacity(s3));

}
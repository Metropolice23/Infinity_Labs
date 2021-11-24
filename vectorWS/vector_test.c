#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vector.h"

    /**************************************************************/
    /*********************** Vector-Test ***************************/
    /**************************************************************/

int main ()
{

    int num1 = 34;
    int num2 = 102;
    int num3 = 77;
    int num4 = 51;

    char cr1 = 'W';
    char cr2 = 't';
    char cr3 = 'F';

    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n$$$$$$$$$---Vector Test---$$$$$$$$$");
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


    /*********************** Create-Test ***************************/
    printf("\n-------------Create Test---------------\n");

    size_t cap1 = 30;
    size_t cap2 = 40;
    size_t cap3 = 50;
    size_t cap4 = 60;

    size_t dt1 = sizeof(int);
    size_t dt2 = sizeof(int);
    size_t dt3 = sizeof(char);
    size_t dt4 = sizeof(int);

    void* v1 = VectorCreate(dt1, cap1);
    void* v2 = VectorCreate(dt2, cap2);
    void* v3 = VectorCreate(dt3, cap3);
    void* v4 = NULL;
    v4 = VectorCreate(dt4, cap4);

    printf("shuold be - \nNOT NULL");
    printf("\nresult is - \n");
    printf("%p\n", v4);
    

    /*********************** Destroy-Test **************************/
    printf("\n-------------Destroy Test---------------\n");

    VectorDestroy(v4);
    v4 = NULL;
    printf("shuold be - \nNULL");
    printf("\nresult is - \n");
    printf("%p\n", v4);
  
    /*********************** Append-Test *****************************/
    printf("\n-------------Append Test---------------\n");

    VectorAppend(v1, &num1);
    VectorAppend(v1, &num2);
    VectorAppend(v1, &num3);
    VectorAppend(v1, &num4);

    printf("\n^^^^^^^%d", *(int*)VectorGet(v1, 3));

    VectorAppend(v3, &cr1);
    VectorAppend(v3, &cr2);
    VectorAppend(v3, &cr3);

    /*********************** Size-Test ******************************/
    printf("\n-------------Size Test---------------\n");

    printf("v1 size should be -\n4\n");
    printf("v1 size is -\n%lu\n", VectorSize(v1));
    printf("v1 size should be -\n0\n");
    printf("v1 size is -\n%lu\n", VectorSize(v2));
    printf("v1 size should be -\n3\n");
    printf("v1 size is -\n%lu\n", VectorSize(v3));

    /*********************** Get-Test *****************************/
    printf("\n-------------Get Test---------------\n");

    printf("v1 print should be -\n34\t102\t77\t51\n");
    printf("v1 print is -\n%lu", VectorSize(v1));
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", *(int*)VectorGet(v1, i));
    }

    printf("\n----------------------------\n");

    printf("v3 print should be -\nW\tt\tF\n");
    printf("v3 print is -\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c\t", *(char*)VectorGet(v3, i));
    }

    /*********************** Pop-Test **************************/
    printf("\n-------------Pop Test---------------\n");

    printf("v1 size should be -\n4");
    printf("\nv1 size is -\n%lu\n", VectorSize(v1));
    VectorPop(v1);
    printf("v1 size should be -\n3");
    printf("\nv1 size is -\n%lu\n", VectorSize(v1));

    printf("\n----------------------------\n");

    printf("v3 size should be -\n3");
    printf("\nv3 size is -\n%lu\n", VectorSize(v3));
    VectorPop(v3);
    printf("v3 size should be -\n2");
    printf("\nv3 size is -\n%lu\n", VectorSize(v3));

    /*********************** IsEmpty-Test *************************/
    printf("\n-------------IsEmpty Test---------------\n");

    VectorAppend(v1, &num2);
    VectorAppend(v1, &num3);
    VectorAppend(v1, &num4);
    printf("shuold be - \n");
    printf("FALSE");
    printf("\nresult is - \n");
    printf("%d\n", VectorIsEmpty(v1));

    printf("\n----------------------------\n");
    printf("shuold be - \n");
    printf("TRUE");
    printf("\nresult is - \n");
    printf("%d\n", VectorIsEmpty(v2));

    printf("\n----------------------------\n");
    printf("shuold be - \n");
    printf("FALSE");
    printf("\nresult is - \n");
    printf("%d\n", VectorIsEmpty(v3));

    /*********************** Capacity-Test *************************/
    printf("\n-------------Capacity Test---------------\n");
    
    printf("v1 capacity shuold be - \n");
    printf("15");
    printf("\nv1 capacity is - \n");
    printf("%lu\n", VectorCapacity(v1));

    for (int i = 0; i < 20; i++)
    {
        VectorAppend(v1, &i);
    }

    printf("v1 capacity shuold be - \n");
    printf("30");
    printf("\nv1 capacity is - \n");
    printf("%lu\n", VectorCapacity(v1));

    printf("\n----------------------------\n");

    printf("v3 capacity shuold be - \n");
    printf("25");
    printf("\nv3 capacity is - \n");
    printf("%lu\n", VectorCapacity(v3));

    cr1 = 'r';

    for (int i = 0; i < 30; i++)
    {
        VectorAppend(v3, &cr1);
    }

    printf("v3 capacity shuold be - \n");
    printf("50");
    printf("\nv3 capacity is - \n");
    printf("%lu\n", VectorCapacity(v3));

    /*********************** End Of Test *************************/
    printf("\n-------------End Of Test---------------\n");

    VectorDestroy(v1);
    VectorDestroy(v2);
    VectorDestroy(v3);

    return 0;
}
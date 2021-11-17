#ifndef __FILE_H__
#define __FILE_H__
#include <stdio.h>
//print int varible of struct print_me
void Print(int num);



typedef   int (*Operation)(FILE *fp, char* FileNeme, char* string );

typedef   int (*Comparison)(char* string, char* string2);


typedef struct two_func 
       {  
         char *string;
         Comparison cmp;
         Operation  opt;
       }STF;    
    


//takes a file name and flags, adds user input to file from end/biginning. Can also remove file / count words / exit itself
int Logger(FILE *f,char *filename, ...);

int Writef(FILE ** fn, char str[]);
int Closef(FILE ** fn, char filenam[]);
int Openf(FILE ** fn, char filenam[]);






#endif


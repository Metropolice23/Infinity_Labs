#ifndef __PHASE2_H__
#define __PHASE2_H__
#include <stdio.h>
#include "phase1.h"

typedef   exitstatus_t (*Operation)(FILE *fp, char* FileNeme, char* string );

exitstatus_t OperationFuncRemove(FILE *fp, char* FileNeme, char* string);

exitstatus_t OperationFuncCountLine(FILE *fp, char* FileNeme, char* string);

exitstatus_t OperationFuncExit(FILE *fp, char* FileNeme, char* string);

exitstatus_t OperationFuncPrintTop(FILE *fp,char* FileNeme, char* string);

exitstatus_t OperationFuncPrintToFile( FILE *fp, char* FileNeme ,char *string);







typedef   int(*Comparison)(char* string, char* string2);

typedef struct Logaction 
       {  
         char *string;
         Comparison cmp;
         Operation  opt;
       }STF; 



#endif

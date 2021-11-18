#ifndef __PHASE2_H__
#define __PHASE2_H__
#include <stdio.h>
#include "phase1.h"

typedef   exitstatus_t (*Operation)(FILE *fp, char* FileNeme, char* string );

exitstatus_t RemoveFile(FILE *fp, char* FileNeme, char* string);

exitstatus_t CountLines(FILE *fp, char* FileNeme, char* string);

exitstatus_t ExitFile(FILE *fp, char* FileNeme, char* string);

exitstatus_t SetStart(FILE *fp,char* FileNeme, char* string);

exitstatus_t Writef( FILE *fp, char* FileNeme ,char *string);







typedef   int(*Comparison)(char* string, char* string2);

typedef struct Logaction 
       {  
         char *string;
         Comparison cmp;
         Operation  opt;
       }STF; 



#endif

#ifndef __PHASE1_H__
#define __PHASE1_H__

typedef enum  exitstatus_t { REMOVE , COUNTLINE, EXIT, APPEND, WRITE} exitstatus_t;

void Print(int num);




//takes a file name and flags, adds user input to file from end/biginning. Can also remove file / count words / exit itself
int Logger(char *filename);





#endif


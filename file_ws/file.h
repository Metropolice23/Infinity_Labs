#ifndef __FILE_H__
#define __FILE_H__
#include <stdio.h>

//print int varible of struct print_me
void Print(int num);
//takes a file name and flags, adds user input to file from end/biginning. Can also remove file / count words / exit itself
int Logger(FILE *f, ...);

#endif

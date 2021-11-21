#ifndef  __STRING_H__
#define __STRING_H__
#include <stdio.h>

int strCmp (const char* str1, const char* str2);
int strLen (const char* str);
int strnCmp(const char *s, const char *t, size_t num);
void ToLower(char *str);

#endif
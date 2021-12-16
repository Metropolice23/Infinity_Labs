#include <stdio.h>

#ifndef  __pointersFunc_H__
#define __pointersFunc_H__

void Swap(int* a, int* b);
void SwapSize(size_t* x, size_t* y);
void CopyArray (int *arr1, int* arr2, int leng);
void SwapSizeP(size_t** c, size_t** d);
void SwapSizePc(size_t** c, size_t** d);
void SwapSizePd(size_t** cp2, size_t** dp2);
int strLen (const char* str);
int strCmp (const char* str1, const char* str2);

#endif

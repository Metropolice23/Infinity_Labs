#ifndef  __STRING_H__
#define __STRING_H__
#include <stdio.h>

//Copies the string pointed to, by src to dest.
char *strcpy(char *dest, const char *src);
//Copies up to n characters from the string pointed to, by src to dest.
char *strncpy(char *dest, const char *src, size_t n);
//Appends the string pointed to, by src to the end of the string pointed to by dest.
char *strcat(char *dest, const char *src);
//Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
char *strncat(char *dest, const char *src, size_t n);
//Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
char *strchr(const char *str, int c);
//Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
size_t strspn(const char *str1, const char *str2);
//Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
char *strstr(const char *haystack, const char *needle);
//Breaks string str into a series of tokens separated by delim.
char *strtok(char *str, const char *delim);
//compares string1 and string2 without sensitivity to case. All alphabetic characters in string1 and string2 are converted to lowercase before comparison.
int strcasecmp(const char *string1, const char *string2);
//Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by str1. The returned pointer must be passed to free to avoid a memory leak. 
char * strdup( const char *str1 );
int strCmp (const char* str1, const char* str2);
int strLen (const char* str);
int strnCmp(const char *s, const char *t, size_t num);
void ToLower(char *str);



#endif

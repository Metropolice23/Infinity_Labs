#include "str.h"


void ToLower(char *str)
{
    while(*str != '\0')
    {
        if(*str >=65 && *str<=90)
        {
            *str = *str + 32;
        }
        str++;
    }

}



	

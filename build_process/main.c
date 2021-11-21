#include <stdio.h>
#include "g.h"
int g_s;
int main()
{
    printf("%d\n", g_s);
    Foo();
    printf("%d\n", g_s);
}
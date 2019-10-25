#include <stdio.h>

int main()
{
    int a = 3;
    int b = 5;
    int c = 0;

    printf("%d", ((a * b) - (((a>>31)+a)>>1)));
    return 0;
}


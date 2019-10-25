#include <stdio.h>

int main()
{
    // Define 3 integers
    int a = 3;
    int b = 5;
    int c = 0;

    // Subtract the a right-shifted value of integer a from the product of a and b.
    // Print the result.
    printf("%d", ((a * b) - (((a>>31)+a)>>1)));
    return 0;
}


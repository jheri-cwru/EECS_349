#include <stdio.h>

int proc1(int *d, int e, int f);

int main()
{
    int a = 7;
    int b = 100;
    int c = 0;
    
    
    while(c<b)
    {
    	c++;
	}
	
	printf("%d", proc1(a,b,c));
	
	return 0;
}

int proc1(int *d, int e, int f)
{
	return (f/2);
}

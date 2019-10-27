#include <stdio.h>

int main()
{
	int vars[] = {12,15,221,3,432,54,16,67};
    
	int i = 0;
	int j = 0;

	goto function1;
    
	function2:

		if(vars[j] > i)
		{
			goto function3;		
		}

		i = vars[j];
		
	function3:

		j++;
    	
	function1:
    	
		if(j > 7)
		{
			printf("%d", i);
		}
		else
		{
			goto function2;
		}
	
	return 0;
}



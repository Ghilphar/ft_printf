#include <stdio.h>
/*
// bit returned at location
int bit_return(int a, int loc)   
{
    int buf = a & 1<<loc;

    if (buf == 0) return 0;
    else return 1; 
}

int main() 
{
	
    //11000010111011010100000000000000  
    // 1 sign bit | 8 exponent bit | 23 fraction bits
    float a = 1.145; 
    int *b;
    b = (int *)&a;

    int i;
    for (i = 31; i >= 0; i--)
    {
		if (i == 30)
			printf(" ");
		if (i == 22)
			printf(" ");
        printf("%d",bit_return(*b,i));
    }

	
	printf("\n%f\n", a );    return 0;
	
}
*/
#include <stdio.h>
int main(void) {

	double f;

	f = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.566;
	printf("%-+50f\n", f);

	return 0;
}

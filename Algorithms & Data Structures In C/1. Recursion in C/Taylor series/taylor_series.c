// Recursiive function for Taylor Series
// Taylor Series: e^x = 1 + 2/1 + (x^2)/2! + (x^3)/3! + ... + n terms


// x is the power, n are the terms
#include <stdio.h>



double taylor(int x, int n)
{
	static double p = 1, f = 1;
	double r;
	if(n == 0) {
		return 1;
	}
	r = taylor(x, n - 1);
	p = p*x;
	f = f*n;
	return r+p/f;
}

int main()
{
	printf("%g\n", taylor(3,10));
	return 0;
}
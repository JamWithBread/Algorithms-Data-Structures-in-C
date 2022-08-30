// Applying a power using recursion

#include <stdio.h>

int power(m, n) 
{
	if (n==1){
		return m;
	}

	return power(m,n-1) * m;
}

int main() 
{
	printf("%d\n", power(5,3));
}
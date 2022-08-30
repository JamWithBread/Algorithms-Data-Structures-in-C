// Sum of all n natural numbers

#include <stdio.h>

int sum(n) 
{
	if (n == 1){
		return 1;
	}
	return sum(n-1) + n;
}

int main()
{
	printf("%d\n",sum(7));
}
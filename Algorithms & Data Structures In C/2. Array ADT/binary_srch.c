// Binary search 

#include <stdio.h>
#include <stdlib.h>

struct Array {
	int A[30];
	int length;
	int size;
};

int BinSearch(struct Array arr, int item) 
{
	int l = 0;
	int h = arr.length-1;
	int m;

	while(l <= h){
		m = (l+h)/2;
		if (item == arr.A[m]) {
		return m;
		}
		else if (item < arr.A[m]) {
		h = m-1;
		}
		else {
		l = m +1;
		}
		
	}
	printf("Element is not present in array")
	return -1;
}

int main(void)
{
	struct Array arr = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}, 20, 30};
	printf("%d\n",BinSearch(arr, 17));
}
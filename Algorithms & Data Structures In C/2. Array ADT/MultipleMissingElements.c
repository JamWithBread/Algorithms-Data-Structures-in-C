#include <stdio.h>
#include <stdlib.h>

// Assume array is sorted 

struct Array {
	int A[30];
	int length;
	int size;
};


int MultipleMissingElements(struct Array arr)
{
	int i,j;
	if (arr.length > 0) {
		for(i =0, j=1; i<arr.length; i++, j++) {
			if(arr.A[j] - arr.A[i] > 1) {
				return arr.A[i]+1;
			}
		}
	}
	return -1;
}


int main(void)
{
	struct Array arr = {{1,2,3,6,7,8,9,10,12,13,14,15,16,17,18,19,20}, 17, 30};
	int result;
	result = MultipleMissingElements(arr);
	printf("The missing element is %d\n", result);
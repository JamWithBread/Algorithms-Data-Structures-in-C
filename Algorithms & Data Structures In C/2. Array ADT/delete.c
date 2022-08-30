#include <stdio.h>
#include <stdlib.h>

struct Array 
{
	int A[10];
	int length;
	int size;

};

void Display(struct Array arr)
{
	int i;
	printf("\nArray contains:");
	for (i=0; i<arr.length; i++){
		printf("\n%d", arr.A[i]);
	}
}

void Delete(struct Array *arr, int x)
{
	int i;
	if (arr -> length > 0) {
		for (i = x; i < arr ->length-1; i++) {
			arr -> A[i] = arr-> A[i+1];
		}
	arr -> length--;
	}
}

int main(void)
{
	struct Array arr = {{1,2,3,4,5}, 5, 10};
	Display(arr);

	Delete(&arr,2);
	Display(arr);
}

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
	if (arr.length>0) {
		int i;
		printf("The elements of the array are\n");
		for(i = 0; i < arr.length; i++) {
			printf("%d ", arr.A[i]);
		}

	}
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));


	while(i < arr1 ->length && j < arr2 ->length) {
		if(arr1 ->A[i] < arr2 ->A[j]) {
			arr3 ->A[k++] = arr1 ->A[i++];
		}
		else {
			arr3 ->A[k++] = arr2 -> A[j++];
		}
	}
	for (;i < arr1 ->length; i++)
		arr3 ->A[k++] = arr1 ->A[i];

	for (;j < arr2 ->length; j++)
		arr3 ->A[k++] = arr2 ->A[j];

	arr3 -> length = arr1 ->length + arr2 ->length;
	arr3 -> size = 10;

	return arr3;
}

int main(void) 
{
	struct Array arr1 = {{1,2,3,4,5}, 5,10};
	struct Array arr2 = {{6,7,8,9,10}, 5, 10};
	struct Array *arr3;
	arr3 = Merge(&arr1, &arr2);
	Display(*arr3);
	return 0;
}
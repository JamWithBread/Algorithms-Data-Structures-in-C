# include <stdio.h>
# include <stdlib.h>


struct Array {
	int A[10];
	int length;
	int size;
};

void Display(struct Array arr) 
{
	if(arr.length > 0) {
		printf("\nThe elements of the array are: \n");
		for(int i = 0; i < arr.length; i++) {
			printf("%d ", arr.A[i]);
		}
	}

}


void InsertSorted(struct Array *arr, int item)
{
	int i = arr ->length -1;
	while(arr->A[i] > item) {
		arr ->A[i+1] = arr ->A[i];
		i--;
	}
	arr ->A[i+1] = item;
}


int CheckSorted(struct Array arr)
{
	if (arr.length > 0) {
		int i, j;
		for(i = 0, j=1; i< arr.length-1; i++,j++) {
			if (arr.A[i] > arr.A[j])
				return -1;
		}
	}
	return 1;
}


int main(void) 
{
	struct Array arr = {{2,4,7,8,9,12,15,17,19}, 10, 20};

	Display(arr);

	InsertSorted(&arr, 14);
	Display(arr);

	
	printf("Is the Array sorted? result: %d", CheckSorted(arr));

}
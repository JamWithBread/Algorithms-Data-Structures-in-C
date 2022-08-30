#include <stdio.h>
#include <stdlib.h>


struct Array 
{
	int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < arr.length; i++) {
		printf("%d", arr.A[i]);
	}
}

// function returns nothing, so to modify the array it should be call by address (*arr)
void Append(struct Array *arr, int x)
{
	if (arr -> length < arr -> size) {
		arr -> A[arr -> length++] = x;
	}
}

void Insert(struct Array *arr, int index, int x)
{
	int i;
	if (arr -> length < arr -> size && index < arr -> size) {
		for (i = arr->length; i >= index; i--) {
			arr -> A[i+1] = arr -> A[i];
		}
		arr -> A[index] = x;
		arr -> length++;
	}
}

int main(void) 
{
	struct Array arr = {{2,3,4,5,6},10,5};

	Append(&arr, 10);
	Append(&arr, 8);
	Append(&arr, 9);
	Insert(&arr,1,7);
	Display(arr);

	return 0;
}
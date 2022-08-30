# include <stdio.h>
# include <stdlib.h>

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
		printf("\nThe elements of the array are\n");
		for(i = 0; i < arr.length; i++) {
			printf("%d ", arr.A[i]);
		}

	}
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));


	while(i < arr1 ->length && j < arr2 ->length) {
		if(arr1 -> A[i] == arr2 ->A[j]) {
			arr3 -> A[k++] = arr1 ->A[i++];
			j++;
		}

		else if(arr1 ->A[i] < arr2 ->A[j]) {
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

	arr3 -> length = k;
	arr3 -> size = 20;

	return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	struct Array *arr4 = (struct Array *)malloc(sizeof(struct Array));


	while(i < arr1 ->length && j < arr2 ->length) {
		if(arr1 -> A[i] == arr2 ->A[j]) {
			arr4 -> A[k++] = arr1 ->A[i++];
			j++;
		}

		else if(arr1 ->A[i] < arr2 ->A[j]) {
			i++;
		}
		else {
			j++;
		}
	}


	arr4 -> length = k;
	arr4 -> size = 20;

	return arr4;
}

int main(void) 
{
	struct Array arr1 = {{1,2,3,3,4,8,10}, 7,20};
	struct Array arr2 = {{1,5,5,15,20}, 5, 20};
	struct Array *arr3;
	struct Array *arr4;

	arr3 = Union(&arr1, &arr2);
	arr4 = Intersection(&arr1, &arr2);

	Display(*arr3);
	Display(*arr4);

}
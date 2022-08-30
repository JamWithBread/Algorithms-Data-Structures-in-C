// Find multiple missing elements in sorted AND unsorted arrays

#include <stdio.h>
#include <stdlib.h>

struct Array {
	int A[30];
	int length;
	int size;
};

void MultipleMissingElements(struct Array arr)
{
	int dif, i;
	if (arr.length > 0) {
		dif = arr.A[0];
		for (i=0; i<arr.length; dif++, i++) {
			//printf("The current index is %d, current element is %d, current difference is %d \n", i, arr.A[i], arr.A[i]-dif);
			if (arr.A[i] - dif > 1) {
				int offset;
				offset = arr.A[i] - dif;
				dif += offset;
				for (int k = offset; k>=1; k--) {
					printf("%d is missing\n", arr.A[i]-k);
				}
			}
		}
	}
}

//Multiple missing in an unsorted array (fast)

void MultipleMissingElementsUnsorted(struct Array arr1)
{
	struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
	arr2 -> length = arr1.size;
	int i;

	for (i = 0; i< arr1.length; i++) {
		int index = arr1.A[i];
		arr2 -> A[index] +=1;
	}

	//for (i = 0; i < arr2 -> length; i++){
		//printf("index: %d element: %d", i, arr2 ->A[i]);
	//}

	for (i = 0; i < arr2 -> length; i++) {
		if (arr2 ->A[i] == 0) {
			printf("Element %d is missing\n", i);
		}
	}
}

int main(void)
{
	printf("Sorted Array:\n");
	struct Array arr = {{4,5,6,7,8,9,10,14,15,18,19,20}, 12, 30};
	MultipleMissingElements(arr);


	printf("Unsorted Array:\n");
	struct Array arr1 = {{3,5,9,2,7,8,15,1,6}, 9,15};
	MultipleMissingElementsUnsorted(arr1);

}
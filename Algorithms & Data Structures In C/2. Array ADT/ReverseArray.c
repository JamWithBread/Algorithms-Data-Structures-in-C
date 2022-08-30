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

void Reverse(struct Array *arr)

{
	if (arr -> length > 0) {
		int i,j, temp;
		for(i = 0, j = arr ->length-1; i < j; i++, j--) {
			temp = arr -> A[i];
			arr -> A[i] = arr -> A[j];
			arr -> A[j] = temp;
		}
	}
}



int main(void) 
{
	struct Array arr = {{1,2,3,4,5,6,7,8,9,10}, 10, 10};

	Display(arr);
	Reverse(&arr);
	Display(arr);

}
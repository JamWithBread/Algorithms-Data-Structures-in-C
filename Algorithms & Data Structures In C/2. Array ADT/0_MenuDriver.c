# include <stdio.h>
# include <stdlib.h>

// Do-while main function loop for a program where you can choose array opperations

struct Array
{
	int length;
	int size;
	int *A;
	
};

void Create(struct Array *arr)
{
	int i;
	printf("Enter the maximum size of your array: ");
	scanf("%d", &arr->size);

	arr->A = (int*)malloc(arr->size*sizeof(int));

	printf("Enter the number of elements your array will contain: ");
	scanf("%d", &arr->length);
	printf("Enter each element of your array: ");
	for (i = 0; i < arr->length; i++)
	{
		scanf("%d", &arr -> A[i]);
		
	}
}

void Display(struct Array arr)
{
	int i;
	printf("\nElements of array are \n");
	for (i = 0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

// Array operation functions:

// 1
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

// 2
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
// 3
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
	return -1;
}

// 4

int Sum(struct Array arr) 
{ 
	int total = 0;
	if (arr.length > 0 ){
		for (int i = 0; i < arr.length; i++) {
			total += arr.A[i];
		}
	}
	return total;
}

// 5
int Avg(struct Array arr) 
{ 
	int total = 0;
	if (arr.length > 0 ){
		for (int i = 0; i < arr.length; i++) {
			total += arr.A[i];
		}
	}
	return total/arr.length;
}


// 6
int Min(struct Array arr)
{
	int min = arr.A[0];
	for(int i = 1; i < arr.length; i++) {
		if (arr.A[i] < min) {
			min = arr.A[i];
		}
	}
	return min;
}

int Max(struct Array arr)
{
	int max = arr.A[0];
	for(int i = 1; i < arr.length; i++) {
		if (arr.A[i] > max) {
			max = arr.A[i];
		}
	}
	return max;
}

// 7 

int CheckSorted(struct Array arr)
{
	if (arr.length > 0) {
		int i, j;
		for(i = 0, j=1; i< arr.length-1; i++,j++) {
			if (arr.A[i] > arr.A[j])
				return 0;
		}
	}
	return 1;
}

// 8
void BubbleSort(struct Array *arr)
{
	int right = arr->length -1;
	int temp = 0;
	while (right > 0) 
	{
		int k = 0;
		for (int i = 0; i < right; i ++) 
		{
			if (arr->A[i+1] < arr->A[i]) 
			{
				temp = arr->A[i+1];
				arr->A[i+1] = arr->A[i];
				arr->A[i] = temp;
				k = i;
			}
		}
	right = k;
	}
}
// 9 
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
	struct Array arr1;
	Create(&arr1);

	int ch; 
	do
		{
		printf("\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search for element\n");
		printf("4. Sum array\n");
		printf("5. Get Average\n");
		printf("6. Get Min and Max\n");
		printf("7. Check if array is sorted\n");
		printf("8. Sort array\n");
		printf("9. Reverse array\n");
		printf("10. Exit\n");

		int item, index, result, result2;
		
		printf("Enter your choice ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter an element and index: ");
					scanf("%d%d", &item, &index);
					Insert(&arr1, index, item);
					printf("Result: ");
					Display(arr1);
					break;
			case 2: printf("Enter the index of the element to be deleted: ");
					scanf("%d", &index);
					Delete(&arr1, index);
					printf("Result: ");
					Display(arr1);
					break;
			case 3: printf("Enter the element you would like to know the index of: ");
					scanf("%d", &item);
					result = BinSearch(arr1, item);
					printf("Item %d is at index %d\n", item, result);
					break;
			case 4:	result = Sum(arr1);
					printf("The sum of all elements in the array is: %d", result);
					break;
			case 5: result = Avg(arr1);
					printf("The average of all elements in the array is %d", result);
					break;
			case 6: 
					result = Min(arr1);
					result2 = Max(arr1);
					printf("The minimum element of the array is %d and the max is %d\n", result, result2);
					break;
			case 7: result = CheckSorted(arr1);
					if (result)
						printf("Array is sorted\n");
					else
						printf("Array is not sorted\n");
					break;
			case 8: printf("Array has been sorted. Result: \n");
					BubbleSort(&arr1);
					Display(arr1);
					break;
			case 9: printf("Array has been reversed. Result: \n");
					Reverse(&arr1);
					Display(arr1);
					break;
			


		}

	} while (ch < 10);
	return 0;

}
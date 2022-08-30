#include <stdio.h>
#include <stdlib.h>


struct Array {
	int A[10];
	int length;
	int size;
};

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length) {
		return arr.A[index];
	}
	return -1;
}

void Set(struct Array *arr, int index, int item)
{
	if (index >= 0 && index < arr -> length) {
		arr -> A[index] = item;
	}
}

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

int main(void) 
{
	struct Array arr = {{1,2,3,4,5,6,7,8}, 8, 10};
	int a, b, c, d;
	a = Get(arr, 3);
	Set(&arr, 1,5);
	b = arr.A[1];
	c = Avg(arr);
	d = Max(arr);

	printf("Get = %d, Set =%d, Avg = %d, Max = %d", a, b, c, d);
}
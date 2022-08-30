#include <stdio.h>
#include <stdlib.h>


struct Array
{
	int A[10];
	int length;
	int size;
};

int LinSearch(struct Array arr, int item)
{
	if (arr.length > 0){
		int i;
		for (i = 0; i < arr.length; i++) {
			if (arr.A[i] == item){
				printf("\nindex of item is %d", i);
				return i;
			}	
		}
	}
	return -1;
}

int ImprovedLinSearch(struct Array arr, int item)
{
	// After the search occurs, swap the search element with the one before it so the search next time 
	// will be one element faster

	//or

	// place the search item at index 0 and move all other items down one index
}

int main(void)
{
	struct Array arr = {{1,2,3,4,5,6,7,8,9}, 9, 10};

	LinSearch(arr, 7);
}
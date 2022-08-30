// Hasing implementation using linear probing for collision resolution
#include <stdio.h>

#define SIZE 10

int Hash(int key)
{
	return key%SIZE;
}

int Probe(int H[], int key)
{
	int index = Hash(key);
	int i = 0;
	while(H[(index+i)%SIZE]!=0)
	{
		i++;
	}
	return (index+i)%SIZE;
}

void Insert(int H[], int key)
{
	int index = Hash(key);

	if(H[index]!=0)
	{
		index = Probe(H,key);
	}
	H[index] = key;
}

void Display(int H[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ", H[i]);
	}
	printf("\n");
}

int Search(int H[], int key)
{
	int index = Hash(key);

	int i = 0;
	while(H[(index+i)%SIZE]!=key)
	{
		i++;
	}
	return (index+i)%SIZE;
}

int main(void)
{
	int HT[10] = {0};
	Insert(HT,12);
	Insert(HT,25);
	Insert(HT,13);
	Insert(HT,22);

	Display(HT,10);

	printf("Key found at %d\n", Search(HT,22));

	return 0;
}
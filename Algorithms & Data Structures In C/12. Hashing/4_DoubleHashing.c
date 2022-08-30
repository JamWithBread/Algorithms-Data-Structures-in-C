// Hashing implemented using double hasing -> Prevents collisions, clustering, and reduces # of iterations over quadratic probing

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Array 
{
	int size;
	int *A;
};

int IsPrime(int x)
{
	if(x<2)
		return 0;
	for(int i = 2; i<x; i++)
	{
		if(x%i ==0)
			return 0;
	}
	return 1;
}


//used to find largest prime numbered index in array structure
int LargestPrime(int n)
{
	int i = n;
	while(i>0)
	{
		if(IsPrime(i))
			return i;
		else
			i--;
	}
	return 0;
}

int Hash(int key)
{
	return key%SIZE;
}

int PrimeHash(int key,int prime)
{
	return prime - (key % prime);
}

int Probe(struct Array H, int key)
{
	int prime = LargestPrime(H.size);
	int index = Hash(key);
	int i = 0;
	while(H.A[(Hash(index) + i * PrimeHash(key, prime)) % SIZE] != 0)
	{
		i++;
	}
	return (index+i*PrimeHash(key, prime))%SIZE;
}

void Insert(struct Array H, int key)
{
	int index = Hash(key);

	if(H.A[index]!=0)
	{
		index = Probe(H,key);
	}
	H.A[index] = key;
}

void Display(struct Array H)
{
	int i;
	for(i=0; i<H.size; i++)
	{
		printf("%d ", H.A[i]);
	}
	printf("\n");
}

int Search(struct Array H, int key)
{
	int index = Hash(key);
	int prime = LargestPrime(H.size);

	int i = 0;
	while(H.A[(Hash(index) + i * PrimeHash(key, prime)) % SIZE] != key)
	{
		i++;
		if(H.A[(Hash(index) + i * PrimeHash(key, prime)) % SIZE] == 0)
			return -1;
	}
	return (index+i*PrimeHash(key, prime))%SIZE;
}

int main(void)
{
	struct Array HT;
	HT.size = 10;
	HT.A = (int*)malloc(HT.size*sizeof(int));
	for(int i = 0; i<10; i++)
	{
		HT.A[i] = 0;
	}

	Insert(HT,5);
	Insert(HT,25);
	Insert(HT,15);
	Insert(HT,35);
	Insert(HT,95);

	Display(HT);

	printf("Key %d found at index %d\n",HT.A[Search(HT,25)], Search(HT,25));

	return 0;
}
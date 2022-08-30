

#include <stdio.h>
#include <stdlib.h>

#include "chains_header.h"

int Hash(int key)
{
	return key%10;
}

void InsertHT(struct Node *H[], int key)
{
	int index = Hash(key);
	SortedInsert(&H[index], key);
}

void DisplayHT(struct Node **HT, int size)
{
	int i;
	struct Node *p;
	for(i = 0; i<size; i++)
	{
		printf("HT[%d]: ", i);
		if(HT[i] == NULL)
		{
			printf("NULL\n");
		}
		else
		{
			p = HT[i];
			while(p)
			{
				printf("%d ", p->data);
				p = p->next;
			}
		}
		printf("\n");
	}
}



int main(void)
{
	struct Node *HT[10];
	struct Node *temp;
	int i;

	for(i=0; i<10; i++)
		HT[i] = NULL;

	InsertHT(HT,2);
	InsertHT(HT,12);
	InsertHT(HT,22);
	InsertHT(HT,22);
	InsertHT(HT,42);
	InsertHT(HT,52);

	InsertHT(HT,45);
	InsertHT(HT,55);
	InsertHT(HT,15);
	InsertHT(HT,25);

	DisplayHT(HT,10);

	int key = 22;
	temp = Search(HT[Hash(key)], key);
	printf("Search for %d is found\n",temp->data);
	printf("------------------------------\n");
	key = 15;
	printf("Deleting %d\n",key);
	Delete(&HT[Hash(key)],key);
	DisplayHT(HT,9);



	return 0;
}








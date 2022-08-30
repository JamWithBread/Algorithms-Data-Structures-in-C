// Sparse matrix representation and addition

#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int i;
	int j;
	int x;
};

struct Sparse
{
	int m;
	int n;
	int num;
	struct Element *ele;
};

void Create(struct Sparse *s)
{
	int i;
	printf("Enter dimensions m x n: ");
	scanf("%d%d", &s->m, &s->n);
	printf("Enter number of non-zero elements: ");
	scanf("%d", &s->num);

	s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

	printf("Enter all non-zero elements and their indices in 'm x n x element' format: ");
	for (i = 0; i < s->num; i++) {
		scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
	}
}

struct Sparse * Add(struct Sparse *s1, struct Sparse *s2)
{
	struct Sparse *sum;
	int i,j,k;
	i=j=k=0;

	if(s1 -> m!= s2 -> m || s1 -> n != s2 -> n) {
		printf("Error: Attempting to add matrices of unequal size");
		return 0;
	}
	else {
		sum = (struct Sparse *)malloc(sizeof(struct Sparse));
		sum -> m = s1 -> m; sum -> n = s1 ->n;
		sum -> ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));
	}
	while (i < s1 -> num && j < s2 ->num) {
		// row numbers compared, whichever is smaller is copied
		if (s1->ele[i].i < s2 ->ele[j].i) {
			sum -> ele[k++] = s1->ele[i++];
		}
		else if (s1-> ele[i].i > s2 ->ele[j].i) {
			sum -> ele[k++] = s2 ->ele[j++];
		}
		// elements occurs on same row, check columns. Whichever is smaller is copied
		else {
			if (s1 -> ele[i].j < s2 -> ele[j].j) {
				sum -> ele[k++] = s1 -> ele[i++];
			}
			else if (s1 -> ele[i].j > s2 -> ele[j].j) {
				sum -> ele[k++] = s2->ele[j++];
			}
			// Final else, elements are in the same position, add them
			else {
				// copy s1's info at this position
				sum -> ele[k] = s1 ->ele[i++];
				// add x value at s2 to x value of new entry
				sum -> ele[k++].x += s2 -> ele[j++].x;
			}
		}
	}
	// If above loop terminates and there are elements still left in s1 or s2, add them to sum
	for(;i<s1->num; i++) {
		sum -> ele[k++] = s1 -> ele[i];
	}
	for(;i<s2->num; j++) {
		sum -> ele[k++] = s2 -> ele[j];
	}

	sum -> num = k;
	return sum;
}
	


void Display(struct Sparse s)
{
	int i,j,k=0;
	for (i=0; i < s.m; i++) {
		for (j= 0; j< s.n; j++) {
			if (i==s.ele[k].i && j==s.ele[k].j) {
				printf("%d ", s.ele[k].x);
				k++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}


int main(void)
{
	struct Sparse s1, s2, *s3;
	Create(&s1);
	Create(&s2);
	s3 = Add(&s1, &s2);

	printf("First Matrix\n");
	Display(s1);
	printf("Second Matrix\n");
	Display(s2);
	printf("Resulting (sum) Matrix\n");
	Display(*s3);

}
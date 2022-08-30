// Prim's Minimum Cost Spanning Tree algorithm

#include <stdio.h>

#define I 32767

// first column and first row of matrix are not used
int cost[][8] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
//index 0 of near[] is not used
int near[8] = {I,I,I,I,I,I,I,I};
int t[2][7];

int main(void)
{

	int i,j,k,u,v,n=7, min=I;

	//Find smallest edge and initialize t with the nodes which it connects
	for(i=1; i<=n; i++)
	{
		for(j=i; j<=n; j++)
		{
			if(cost[i][j] < min)
			{
				min=cost[i][j];
				u = i;
				v = j;
			}
		}
	}
	t[0][0] = u;
	t[1][0] = v;

	//initialize near array
	near[u] = near[v] = 0;

	for(i=1; i<=n; i++)
	{
		if(near[i] !=0)
		{
			if(cost[u][u] < cost[i][v])
			{
				near[i] = u;
			}
			else
				near[i] = v;
		}
	}

	// Find path through remaining edges
	for(i=1; i<n-1; i++)
	{
		min = I;
		for(j=1; j<=n; j++)
		{
			if(near[j] != 0 && cost[j][near[j]] < min)
			{
				k = j;
				min = cost[j][near[j]];
			}
		}
		t[0][i] = k;
		t[1][i] = near[k];
		near[k] = 0;

		//Check if other vertices are nearer to k;
		for(j=1; j<=n; j++)
		{
			if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
				near[j] = k;
		}
	}

	//print path
	for(i=0; i<n-1; i++)
	{
		printf("(%d,%d): %d\n", t[0][i], t[1][i], cost[t[0][i]][t[1][i]]);
	}



	return 0;
}





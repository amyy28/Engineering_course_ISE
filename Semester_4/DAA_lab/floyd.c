#include<stdio.h>
#include<math.h>


void main()
{
	int adj[10][10],n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adj matrix \n");
	for(int i = 0 ; i<n ; i++)
		for(int j = 0 ; j<n ; j++)
			scanf("%d",&adj[i][j]);

	for(int k = 0 ; k < n ; k++)
		{
			for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0 ; j < n ; j++)
						{
							//printf("a[%d][%d] = %d a[%d][%d] = %d \n",i,k,adj[i][k],k,j,adj[k][j]);
							if(adj[i][k]+adj[k][j]<adj[i][j])
								adj[i][j] = adj[i][k]+adj[k][j];

						}	
				}		
		}		
		printf("Transitive matrix is\n");
		for(int i = 0 ; i<n ; i++)
		{
			for(int j = 0 ; j<n ; j++)
			printf("%d\t",adj[i][j]);
		
		printf("\n");
		
		}


}

	
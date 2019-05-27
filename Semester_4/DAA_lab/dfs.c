#include<stdio.h>
int a[10][10],n,visited[10];

void dfs(int i)
{
	int j;
	printf("%d",i);
	visited[i] = 1;
	for (j = 0; j < n; j++)
	{
		if(!visited[j]&&a[i][j]==1)
		{
			printf("->");
			dfs(j);
		}
		
	}
}
void main()
{
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	
	}
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	printf("DFS traversal is\n");
	dfs(0);

}


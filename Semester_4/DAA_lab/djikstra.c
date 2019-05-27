#include <stdio.h>
int cost[20][20];
void djikstra(int n,int source)
{
int dis[20],visited[20],count,min,nextnode,i,j;
for (int i = 1; i <=n; i++)
		{
			dis[i] = cost[source][i];
			visited[i]= 0;

		}
		dis[source] = 0;
		visited[source] = 1;
		count = 1;
		while(count<n)
		{
			min = 999;
			for (int i = 1; i <=n; ++i)
				if(dis[i]<min && !visited[i])
				{
					min = dis[i];
					nextnode = i;
				}
				
			visited[nextnode] = 1;
			for (int i = 1; i <= n; ++i)
				if(!visited[i])
					if(min+cost[nextnode][i]<dis[i])
						dis[i] = min+cost[nextnode][i];
						

						count++;
			}
		for (int i = 1; i <=n; ++i)
		{
			if(i!=source)
				printf("\nDistance of node %d from %d = %d",i,source,dis[i]);
		}
		}

		int main()
		{	int n,i,j,source;
			printf("Enter number of vertices\n");
			scanf("%d",&n);
			printf("Enter cost matrix\n");
			for (int i = 1; i <= n ; ++i)
				for (int j = 1; j <=n; ++j)
				{
					scanf("%d",&cost[i][j]);
					/*if(cost[i][j] == 0 && i!=j)
						cost[i][j] = 999;*/
				}
		
		printf("Enter the starting node\n");
		scanf("%d",&source);
		djikstra(n,source);
		return 0;

		}

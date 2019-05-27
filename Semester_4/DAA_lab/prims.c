#include<stdio.h>
#include<string.h>
void main()
{int g[10][10],n;
  printf("Enter the number of vertex\n");
  scanf("%d",&n);
  printf("Enter the distance matrix\n");
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      {
        scanf("%d",&g[i][j]);
      }
      
  }

int selected[n];
memset(selected,0,sizeof(selected));

selected[0] = 1;

for (int i = 0; i < n-1; ++i)
{
      int min = 99999;
      int x = 0, y = 0;
      for (int j = 0; j < n; ++j)
      {
        if(selected[j])
        {
          for (int k = 0; k < n; ++k)
          {
            if(!selected[k] && g[j][k])
            {
                if(min>g[j][k])
                {
                  min = g[j][k];
                  x=j;
                  y=k;
                } 
            }
          }
        }
        
       }
printf("%d - %d : %d\n",x,y,g[x][y]);
selected[y] = 1;
}

}
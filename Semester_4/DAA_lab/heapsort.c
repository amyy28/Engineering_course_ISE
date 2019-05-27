#include<stdio.h>
int a[] = {0,2,9,7,6,5,8};
void heapify(int n)
{
	int i,j,k,v,heap;
	
	for(i = n/2 ; i>=1 ; i--)
	{	k = i;
		heap = 0;
		v = a[k];
		while(!heap && 2*k<=n)
		{
			j = 2*k;
			
			if(j<n)
			{
				if(a[j]<a[j+1])
					j++;
			}
			if(v>=a[j])
			{
				heap = 1;
			}
			else
			{
				a[k] = a[j];
				k = j;
			}
			a[k] = v;

		}
	}

}
void display(int n)
{
	for(int i = 1 ; i <=n ; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void delete(int n)
{
	for (int i = 1; i <n; ++i)
	{
		int j = 1;
		int temp = a[j];
		a[j] = a[n-i+1];
		a[n-i+1] = temp;
		heapify(n-i);
	}
}
void main()
{
	int n = 6;
	
	heapify(n);
	display(n);
	delete(n);
	display(n);

}
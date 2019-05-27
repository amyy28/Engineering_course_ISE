#include<stdio.h>
#include<time.h>
int A[50000];

int main()
{
	clock_t start,end;
	double time_taken;
	int n,i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	start=clock();
	quicksort(A,0,n-1);
	end=clock();
	printf("Sorted array\n");
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
	time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken is:%f\n",time_taken);
	return 0;
}

void quicksort(int A[50000], int first, int last)
{
	int pivot,i,j,temp;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(A[i]<=A[pivot] && i<last)
				i++;
			while(A[j]>A[pivot])
				j--;
			if(i<j)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
		temp=A[pivot];
		A[pivot]=A[j];
		A[j]=temp;
		quicksort(A,first,j-1);
		quicksort(A,j+1,last);
	}
}
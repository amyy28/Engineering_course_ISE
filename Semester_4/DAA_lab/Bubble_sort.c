#include<stdio.h> 
#include<time.h> 
int n,i,y,temp,x; 
int A[100000]; 

void main() 
{ 
	clock_t start,end; 
	double time_taken; 
	printf("Enter the value of n\n"); 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
	{ 
		A[i]=(rand() % 1000) + 1; 
	}

	start=clock(); 
	for(x=0;x<n-1;x++) 
	{ 
		for(y=0;y<n-1-x;y++) 
		{ 
			if(A[y]>A[y+1]) 
			{ 
				temp=A[y]; 
				A[y]=A[y+1]; 
				A[y+1]=temp; 
			} 
		} 
	} 
	end=clock();
	 
	printf("Sorted elements\n"); 
	for(i=0;i<n;i++) 
	{ 
		printf("%d  ",A[i]); 
	} 
	time_taken=(double)(end-start)/CLOCKS_PER_SEC; 
	printf("\nTime taken:%f",time_taken); 
}
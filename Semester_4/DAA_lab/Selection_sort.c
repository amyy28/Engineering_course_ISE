#include<stdio.h> 
#include<time.h> 
int n,i,j,temp; 
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
	
	for(i=0;i<n;i++) 
	{ 
		int small=A[i]; 
		int pos = i; 
		for(j=i+1;j<n;j++) 
		{ 
			if(A[j] < small) { 
				small = A[j]; 
				pos = j; 
			} 
		} 
		int temp = A[pos]; 
		A[pos] = A[i]; 
		A[i] = temp; 
	} 
	
	end=clock();

	printf("Final Array : "); 
	for(i=0;i<n;i++) 
	{ 
		printf("%d  ",A[i]); 
	} 
	time_taken=(double)(end-start)/CLOCKS_PER_SEC; 
	printf("\nTime taken:%f",time_taken); 
}
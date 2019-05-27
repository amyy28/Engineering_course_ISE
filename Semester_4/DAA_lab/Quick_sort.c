#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start,end;
    double time_taken;
    int n,i,upper=1000,lower=0;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        A[i]=(rand() % (upper-lower+1)) + lower;
    }

    start=clock();
    quicksort(A,0,n-1);
    end=clock();
    
    printf("Sorted elements: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
    time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken:%f",time_taken);
    return 0;
}

void quicksort(int A[1000000],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
       pivot=first;
       i=first;
       j=last;
       while(i<j)
       {
           while(A[i]<=A[pivot]&&i<last)
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

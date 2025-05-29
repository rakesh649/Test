#define arr_size 5
#include "header.h"
void recurse_sum(int *arr,int n,int *ptr)
{
    if(n>0)
    {
        if(arr[n]%2 == 0)
            *ptr=*ptr+arr[n];
        recurse_sum(arr,n-1,ptr);
    }
    else
    {
        if(arr[0]%2 == 0)
        *ptr=*ptr+arr[0];
    }
    printf("arr[%d] = %d\n",n,arr[n]);
}
void sum()
{
    int arr[arr_size],i,sum=0;
    for(i=0;i<arr_size;i++)
    scanf("%d",arr+i);
    recurse_sum(arr,arr_size-1,&sum);
    printf("sum = %d\n",sum);
}
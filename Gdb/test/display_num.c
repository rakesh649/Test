#define arr_size 5
#include "header.h"
void recurse(int *arr,int n)
{
    if(n>0)
        recurse(arr,n-1);
    printf("arr[%d] = %d\n",n,arr[n]);
}
void display_num()
{
    int arr[arr_size],i;
    for(i=0;i<arr_size;i++)
    scanf("%d",arr+i);
    recurse(arr,arr_size-1);
}
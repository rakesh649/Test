#include "header.h"


//[1],[1,2],[1,2,3],[1,2,3,4],[2],[2,3],[2,3,4],[3],[3,4],[4]
void sub_array() {
    // Write C code here
    int arr[]={1,2,3,4},i=0,start=0,end=0,n=0;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("sub arrays : sizeof arr = %d\n",n);
    for(start;start<n;start++) {
        for(end=start;end<n;end++) {
                printf("[ ");
            for(i=start;i<=end;i++)
                printf("%d ",arr[i]);
            printf("],");
        }
    }
    return;
}
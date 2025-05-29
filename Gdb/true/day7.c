#include "header.h"
void swap_array(int *a, int *b) {
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
int sort(int *arr, int index,int n) {
    int j,pos=index;
    for(j=index+1;j<=n;j++) {
        if(arr[pos] > arr[j]) {
            pos=j;
        }
    }
    return pos;
}
void selection_sort() {
    int pos=0,i,*arr,n;
    printf("Enter size of the array\n");
    scanf("%d",&n);
    arr=(int *)calloc(1,n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++) {
        pos=sort(arr,i,n-1);
        if(i != pos)
            swap_array(&arr[pos],&arr[i]);
    }
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

void pyramid() {
    int i,j,n;
    printf("Enter height of pyramid\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(int l=0;l<=n-i-1;l++)
            printf(" ");
        for(j=0;j<=i;j++)
            printf("%c ",'*');
        printf("\n");
    }
}
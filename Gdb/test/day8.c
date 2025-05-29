#include "header.h"
void fib() {
    int n,a=0,b=1,c,i;
    printf("Enter series length\n");
    scanf("%d",&n);
    if(n == 1)
        printf("%d",a);
    else if(n == 2)
        printf("%d %d",a,b);
    else {
        printf("%d %d ",a,b);
        for(i=2;i<n;i++) {
            c=a+b;
            printf("%d ",c);
            a=b;
            b=c;
        }
    }
}
int fib_r(int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib_r(n-1)+fib_r(n-2);
}
void recursive_fib() {
    int n,a=0,b=1,c,i;
    printf("Enter series length\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        printf("%d\t",fib_r(i));
}
void fibonacci() {
    //fib();
    recursive_fib();
}
void del_arr() {
    int n,*arr,i,j,k,*arr1;
    printf("Enter size of array\n");
    scanf("%d",&n);
    arr=calloc(1,n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i] == arr[j]) {
                k=i;
                arr=realloc(arr,(n-1)*sizeof(int));
                for(k;k<n;k++) {
                    arr[k]=arr[k+1];
                }
            }
        }
    }
    
    for(i=0;arr[i];i++)
        printf("%d ",arr[i]);
    
}
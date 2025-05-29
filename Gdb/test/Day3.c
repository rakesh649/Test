#include "header.h"
 static void flip_display(int n) {
    int i,mask=1;
    for(i=31;i>=0;i--) {
        if(n&(mask<<i))
            printf("1 ");
        else
            printf("0 ");
    }
 }
 
int trail_zeros(int n) {
    int mask=1,i,bit=0;
    for(i=0;i<31;i++){
        if(!(n & (mask << i)))
            bit++;
        else
            return bit;
    }
}

int lead_zeros(int n) {
    int mask=1,i,bit=0;
    for(i=31;i>=0;i--){
        if(!(n & (mask << i)))
            bit++;
        else
            return bit;
    }
}

void trail_lead_zeros() {
    int n,cnt=0;
    printf("Enter number\n");
    scanf("%d",&n);
    flip_display(n);
    cnt=trail_zeros(n);
    printf("\nTrailing zeros = %d\n",cnt);
    cnt=lead_zeros(n);
    printf("leading zeros = %d\n",cnt);

}

int array_sum(int *arr,int n)
{
  if(n>=0)
    return arr[n]+array_sum(arr,n-1); 
    else
    return 0;
}
void sum_array() {
    int *arr,n,i,sum=0;
    printf("Enter size of array\n");
    scanf("%d",&n);
    arr=(int *)calloc(1,sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    sum=array_sum(arr,n-1);
    printf("sum = %d\n",sum);
    free(arr);
}

void array_search() {
    int *arr,n,i,sum=0,num=0;
    printf("Enter size of array and element to search\n");
    scanf("%d %d",&n,&num);
    arr=(int *)calloc(1,sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++) {
        if(num == *(arr+i)) {
            printf("%d: found\n",num);
            goto end;
        }
    }        
        printf("%d: not found\n",num);
    end:
}

void rotate_arr_left() {
    int *arr,n,i,j,sum=0,num=0,temp=0;
    printf("Enter size of array and posns to rotate_left\n");
    scanf("%d %d",&n,&num);
    arr=(int *)calloc(1,sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(j=0;j<num;j++) {
        for(i=0;i<n;i++) {
            if(i == 0)
                temp=arr[i];
            arr[i-1]=arr[i];
            if(i == (n-1))
                arr[n-1]=temp;
        }
    }
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
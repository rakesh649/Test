#include "header.h"
void delete_substr() {
    int i,cnt=0;
    char main_str[64],sub_str[32],*ptr,ch;
    printf("Enter string1\n");
    scanf("%[^\n]s",main_str);
    while(getchar()!='\n');
    printf("Enter string2\n");
    scanf("%[^\n]s",sub_str);
    printf("main_str = %s sub_str = %s\n",main_str,sub_str);
    //for(i=0;main_str[i];i++) {
        ptr=strstr(main_str,sub_str);
        cnt=ptr-main_str;
        memmove(main_str+cnt,main_str+cnt+strlen(sub_str),strlen(sub_str)+1);
        printf("main str = %s\n",main_str);
    //}
}

void str_int() {
    int i,num=0,mul=1;
    char str[64];
    scanf("%s",str);
    for(i=0;str[i];i++) {
        if('0' <= str[i] && str[i] <= '9')
            continue;
        else
            goto end;
    }
    for(i=strlen(str)-1;str[i];i--) {
        num=num+(str[i]-'0')*mul;
        mul=mul*10;
    }
    end:
    printf("output = %d\n",num);
}
void  descend_order(int *arr , int n) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i] < arr[j]) {
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
}

void  ascend_order(int *arr , int n) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i] > arr[j]) {
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
}

void bubble_sort() {
    int n,i,j,*arr;
    printf("Enter size of array\n");
    scanf("%d",&n);
    arr=calloc(1,n*sizeof(int));
    for(i=0;i<n;i++) {
        scanf("%d",arr+i);
    }
    ascend_order(arr,n);
    printf("Ascend order output\n");
        for(i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    descend_order(arr,n);
        printf("\ndescend order output\n");
        for(i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }

}
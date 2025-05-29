#include "header.h"
void swap_numbers() {
    int a,b;
    printf("Enter a and b\n");
    scanf("%d %d",&a,&b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("a = %d b = %d\n",a,b);
}

void second_largest() {
    int max=-1,second_max=0,*arr,n,i;
    printf("Enter size of array\n");
    scanf("%d",&n);
    arr=(int *)calloc(1,n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++) {
       // if((second_max < arr[i]) && (arr[i] < max))
            
        if(arr[i] > max) {
            second_max=max;
            max=arr[i];
        }
    }
    printf("Max = %d second max = %d\n" ,max,second_max);
}

void str_concatinate() {
    char str[24],str1[24];
    int len=0,i,j=0;
    memset(str,'\0',strlen(str));
    memset(str1,'\0',strlen(str1));
    scanf("%s",str);
    scanf("%s",str1);
    printf("str = %s str1 = %s\n",str,str1);
    len=strlen(str1);
    j=strlen(str);
    for(i=0;str1[i];i++) {
            str[j++]=str1[i];
    }
    str[strlen(str)-1]='\0';
    printf("str = %s\n",str);
}
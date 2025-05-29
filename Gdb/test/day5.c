#include "header.h"
void decimal_binary() {
    int num,sum=0,mul=1;
    printf("Enter binary number\n");
    scanf("%d",&num);
   // num=num/2;
    while(num) {
        sum=sum+num%2*mul;
        mul=mul*10;
        num=num/2;
    }
    printf("%d:binary number = %d\n",num,sum);
}

int fact(int n) {
    if(n>1)
        return n*fact(n-1);
}
void factorial_num() {
   int num,res=0;
   printf("Enter binary number\n");
    scanf("%d",&num);
    res=fact(num);
   printf("Res = %d\n",res);

}

void add_numbers() {
    int a,b,*ptr,*ptr1;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    ptr=&a;
    ptr1=&b;
    printf("sum = %d\n",*ptr + *ptr1);
}
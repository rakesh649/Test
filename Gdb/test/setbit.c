#include "header.h"

void check_polindrome() {
    int n,res=0,sum=0;
    printf("Enter number\n");
    scanf("%d",&n);
    res=n;
    //printf("no of digits = %d\n",cnt);
    while(n) {
        sum=sum*10+n%10;
        n=n/10;
    }
    //printf("sum = %d\n",sum);
    if(sum == res)
        printf("%d: is polindrome number\n",res);
    else
        printf("%d: is not polindrome number\n",res);
}

void check_armstrong() {
    int n,digit=0,res=0,cnt=0;
    printf("Enter number\n");
    scanf("%d",&n);
    res=n;
    while(n) {
        cnt++;
        n=n/10;
    }
    n=res;
    while(n) {
        digit=digit+pow(n%10,cnt);
        n=n/10;
    }
    if(res == digit)
        printf("%d:is armstrong number\n",digit);
    else
        printf("%d:is not armstrong number\n",digit);
}

void display(int n) {
    int i,mask=1;
    for(i=31;i>=0;i--) {
        if(n&(mask<<i))
            printf("1 ");
        else
            printf("0 ");
    }
}
void bit_operations()
{
    int n,mask,i,posn=0;
    printf("Enter number and bit posn\n");
    scanf("%d %d",&n,&posn);
    display(n);
    printf("\nsetting %d posn bit\n",posn);
    n=n|(1 << posn);
    display(n);
    printf("\nclearing %d posn bit\n",posn);
    n=n&~(1 << posn);
    display(n);
}
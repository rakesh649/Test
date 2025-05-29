#include "header.h"
 void flip_display(int n) {
    int i,mask=1;
    for(i=31;i>=0;i--) {
        if(n&(mask<<i))
            printf("1 ");
        else
            printf("0 ");
    }
 }
void flip_bits(){
    int num,i,mask=1;
    printf("Enter number\n");
    scanf("%d",&num);
    printf("number before\n");
    flip_display(num);
    for(i=31;i>=0;i--){
        num = num^(mask << i);
    }
    printf("\nnumber after flip\n");
    flip_display(num);
}
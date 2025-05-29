#include "header.h"
void even_odd() {
    int num;
    printf("Enter num\n");
    scanf("%d",&num);
    if(num & 1)
        printf("%d:is odd number\n",num);
    else
        printf("%d:is even number\n",num);
}
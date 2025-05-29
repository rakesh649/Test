/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "header.h"

void check_powerof2() {
    int n;

    printf("Enter number\n");

    scanf("%d",&n);

    if((n & (n-1))  == 0 && (n != 0))

        printf("%d is power of 2",n);

    else

        printf("%d is NOT power of 2",n);

}

#define R 10
#define C 20

void check_sizeofptrarr() {
   int (*p)[R][C];
   printf("%ld\n",  sizeof(*p));
   getchar();
}

void find_size_withoutsizeof() {
    int var=10,*ptr1=NULL,*ptr2=NULL;

    ptr1=&var;

    ptr2=ptr1+1;

    printf("addr of p = %p, and p1 = %p\n",ptr1,ptr2);

    printf("size of var = %lx\n",(char *)ptr2 - (char *)ptr1);
}

int check_bit(int n, int *p) {
    int posn=0,cnt=0;
    while(n) {
        if((n&1)) {
            *p=posn;
            cnt++;
            if(cnt == 2) 
                return -1;
        }
        posn++;
        n=n>>1;
    }
    return 0;
}

void setbit_posn() {
    int n,ret=0,posn=0;
    printf("Enter num\n");
    scanf("%d",&n);
    ret=check_bit(n,&posn);
    if(ret != -1)
     printf("posn single set = %d\n",posn+1);
    else 
        printf("multiple bits set\n");
}

// #define NUM 5
void insertstr_posn_dyn() {
    char **ptr;
    int n,size=0,i,new_size=0,posn=0;
    printf("Enter num of str's\n");
    scanf("%d",&n);
    
    ptr=(char **)calloc(n,sizeof(char *));
    for(i=0;i<n;i++) {
        printf("Enter str%d size\n",i+1);
        scanf("%d",&size);
        ptr[i]=calloc(1,size);
        printf("Enter str to store\n");
        scanf("%s",ptr[i]);
    }
    
    for(i=0;i<n;i++)
        printf("%d:%s\n",i,ptr[i]);
    
    printf("Expanding the Memory\n");
    printf("Enter new str size and index to insert\n");
    scanf("%d %d",&new_size,&posn);
    
    ptr=(char **)realloc(ptr,sizeof(char *));
    n++;
    for(i=n-1;i>posn;i--)
        ptr[i]=ptr[i-1];
    
    printf("Enter new str to be insert\n");
    ptr[posn]=calloc(1,new_size);
    scanf("%s",ptr[posn]);
    
    printf("After insertion output\n");
    for(i=0;i<n;i++)
        printf("%d:%s\n",i,ptr[i]);
}

#define row 3 
#define col 3
void allocate_2dptr_dyn() {

    int **arr,i;
    arr=(int **)calloc(1,row);
    for(i=0;i<col;i++)
    arr[i]=(int *)calloc(1,col);
}


typedef struct dts {

    int num;

    struct dts *prev;

    struct dts *next;

}dll;

dll *head=NULL;

void add_dll(dll *ptr) {

    dll *new=NULL,*temp=NULL;

    new=calloc(1,sizeof(dll));

    printf("Enter num\n");

    scanf("%d",&new->num);

    new->prev=NULL;

    new->next=NULL;

    if(head == NULL) {

        head=new;

    }

    else {

        for(temp=ptr;temp->next != NULL;temp=temp->next);

        temp->next=new;

        new->prev=temp;

    }

}

void check_fordup(dll *ptr) {

    dll *temp=NULL,*in_temp=NULL;

    for(temp=ptr;temp;temp=temp->next) {

        for(in_temp=temp->next;in_temp;in_temp=in_temp->next) {

            if(temp->num == in_temp->num) {

                in_temp->prev->next=in_temp->next;

                in_temp->next->prev=in_temp->prev;

            }

        }

    }

}
 
// 1 , 2 

void display(dll *ptr) {

    dll *temp=NULL;

    temp=ptr;

    for(temp;temp->next != NULL;temp=temp->next);

    ptr=temp;

    while(ptr) {

        printf("num = %d\n",ptr->num);

        ptr=ptr->prev;

    }

}


void add_dll_rmdup_reverse() {
    int i;
    for(i=0;i<5;i++)
        add_dll(head);

    check_fordup(head);

    display(head); 
}
int isodd(int posn) {
    // printf("p = %d\n",posn);
    if(posn & 1)
        return 1;
    else 
        return 0;
}
void check_powerof4() {
    int num,posn=0,cnt=0;
    printf("Enter number\n");
    scanf("%d",&num);
    while(num) {
        posn++;
        // printf("posn = %d\n",posn);
        if(num & 1) {
            cnt++;
            // printf("cnt = %d and odd = %d\n",cnt,isodd(posn));
            if(cnt == 2) {
                printf("Not power of 4\n");
                break;
            }
        }
        num=num>>1;
    }
    if((cnt == 1) && isodd(posn))
        printf("Is power of 4\n");
}

#if 1
unsigned long int reverseBits(unsigned long int n)
{
    printf("if case\n");
    unsigned long int i=0,j=sizeof(int)*CHAR_BIT-1,bit1=0,bit2=0;
    for(i,j; i<j; i++,j--) {
        // printf("%ld:%ld  %ld:%ld\n",i, ( ( n & (1<<i)) >> i),j, ( (n & (1 << j)) >> j) );
        if( ( ( n & (1<<i)) >> i)  != ( (n & (1 << j)) >> j ) ) {
            n=n^(1<<i);
            n=n^(1<<j);
        }
    }
    return n;
}
#else 

unsigned int reverseBits(unsigned int n)
{
    int i=0,j=sizeof(int)*CHAR_BIT-1,bit1=0,bit2=0;
    for(i,j; i<j; i++,j--) {
        bit1=( (n & (1<<i)) >> i);
        bit2=( (n & (1 << j)) >> j);
        // printf("bit1 = %d bit2 = %d\n",bit1,bit2);
        if(bit1 != bit2) {
            if(bit1) {
                n=n&~(1<<i);
            }
            if(bit2) {
                n=n&~(1<<j);
            }
            n=n|(bit1<<j);
            n=n|(bit2<<i);
        }
    }
    return n;
}
#endif

void bit_display(int n) {
    int i=0;
    for(i=31;i>=0;i--) {
        if(n & (1<<i))
            printf("1 ");
        else
            printf("0 ");
    }
}

void  reverse_bits_num() {
    unsigned int n = 0;
    printf("Enter num\n");
    scanf("%d",&n);
    bit_display(n);
    n=reverseBits(n);
    printf("After reversing bits %u\n",n);
    bit_display(n);
}
int main()
{
    // check_powerof2();
    
    // check_powerof4();
    
    // check_sizeofptrarr();
    
    // find_size_withoutsizeof();
    
    // setbit_posn();
    
    // allocate_2dptr_dyn();
    
    // insertstr_posn_dyn();
    
    // add_dll_rmdup_reverse();
    
    ///////////////////// GENERAL BITWISE TOPIC ///////////////
    
    // reverse_bits_num();
    
    bitwise_operations();
    
    return 0;

}





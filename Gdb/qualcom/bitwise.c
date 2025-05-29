#include "header.h"

static void bit_display(int n) {
    int i=0;
    for(i=31;i>=0;i--) {
        if(n & (1<<i))
            printf("1 ");
        else
            printf("0 ");
            
        if(i%4 == 0)
            printf("  ");
    }
}

void setbit() {
    int num,posn=0;
    printf("Enter num and posn where to set\n");
    scanf("%d %d",&num,&posn);
    num=num|(1<<posn);
    printf("num = %d\n",num);
}

void clearbit() {
    int num,posn=0;
    printf("Enter num and posn where to clearbit\n");
    scanf("%d %d",&num,&posn);
    num=num & ~(1<<posn);
    printf("num = %d\n",num);
}

void togglebit() {
    int num,posn=0;
    printf("Enter num and posn where to togglebit\n");
    scanf("%d %d",&num,&posn);
    num=num ^ (1<<posn);
    printf("num = %d\n",num);
}

#define ByteSwap16(Value) ((Value & 0x00FF) << 8) | ((Value & 0xFF00) >> 8)

#define ByteSwap32(Value) ((Value & 0x000000FF) << 24) | \
                                  ((Value & 0x0000FF00U) <<  8) | \
                                  ((Value & 0x00FF0000U) >>  8) | \
                                  ((Value & 0xFF000000U) >> 24)
                                  
#define ByteSwap64(Value)   ((Value & 0x00000000000000FFU) << 56) | \
                                ((Value & 0x000000000000FF00U) << 40) | \
                                ((Value & 0x0000000000FF0000U) << 24) | \
                                ((Value & 0x00000000FF000000U) <<  8) | \
                                ((Value & 0x000000FF00000000U) >>  8) | \
                                ((Value & 0x0000FF0000000000U) >> 24) | \
                                ((Value & 0x00FF000000000000U) >> 40) | \
                                ((Value & 0xFF00000000000000U) >> 56)
                                
#define ByteSwap1_3(Value)   ( ( Value & 0xff) << 16 | ( Value & (0xff << 16)) >> 16 | ( Value & 0xff00ff00) )

void swap_bytes_num() {
    unsigned int num;
    printf("Enter any hexa decimal num\n");
    scanf("%x",&num);
    num=ByteSwap32(num);
    printf("Swapped num = %x\n",num);
}
#if 1
void swap_even_odd_bits() {
    unsigned short int n=0x3412;
    int i=0;
    bit_display(n);
    printf("After shifting\n");
    for(i=0;i<32;i+=2) {
        if( ( (n & (1 << i) ) >> i) != ( (n & (1 << (i+1) )) >> (i+1) ) ) {
           n=n^(1 << (i+1));
           n=n^(1 << i);
        }
    }
    bit_display(n);
}

#else
void swap_even_odd_bits() {
printf("Efficient code\n");
  int num,e_mask=0x5555,o_mask=0xaaaa;
  printf("Enter num\n");
  scanf("%d",&num);
  bit_display(num);
    printf("After shifting\n");
  num = ((num&e_mask) << 1) | ((num&o_mask) >> 1);
// printf("num = %d\n",num);
    bit_display(num);
    return;
}
#endif

void bitwise_operations() {
    
    // setbit();
    // clearbit();
    // togglebit();
    // swap_bytes_num();
    swap_even_odd_bits();
}
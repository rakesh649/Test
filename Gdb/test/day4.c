#include "header.h"
void leap_yr_check() {
    unsigned int num;
    scanf("%u",&num);
    (num%4==0)?(num%100==0)?(num%400==0)?printf("%d:is a leap year\n",num):printf("%d:is not a leap year\n",num):printf("%d:is a leap year\n",num):printf("%d:is not a leap year\n",num);
}

void word_cnt_revers() {
    char str[128],*ptr;
   // ptr=calloc(1,strlen(str));
    memset(str,'\0',strlen(str));
    scanf("%[^\n]s",str);
    printf("str = %s\n",str);
    ptr=strtok(str," ");
    //while(ptr) {
    printf("str = %s\n",str);

        ptr=strtok(NULL," ");
        printf("str = %s\n",str);
    //}
}

void remove_extra_spaces() {
    char str[128],*ptr;
    int i,j=0;
    memset(str,'\0',strlen(str));
    scanf("%[^\n]s",str);
    for(i=0;str[i];i++) {
        if((str[i] == ' ') && (str[i+1] == ' ')) {
            j=i;
            while(str[j]) {
                str[j++]=str[j+1];
            }
        }
            //memmove(str+i+1,str+i+2,strlen(str+i+2));
    }
    printf("str = %s\n",str);
    
}
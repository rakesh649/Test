#include "header.h"
void reverse_char(char *st,char *end) {
    char temp='\0';
    while(st < end) {
        temp=*st;
        *st=*end;
        *end=temp;
        st++;
        end--;
    }
}
void reverse_words() {
    int i;
    char str[]="nomus comm sys",*start=NULL,*end=NULL;
    //start=end=str;
    for(i=0;str[i];i++) {
        start=end=str+i;
        while(*end != ' ' && *end != '\0') {
            end++;
            i++;
        }
        reverse_char(start,end-1);
    }
    printf("Output str = %s\n",str);
}

void user_strcmp() {
    int i;
    char str[32],str1[32];
    scanf("%s %s",str,str1);
    while(str[i]) {
        if(str[i] > str1[i]) {
            printf("str is greater than str1\n");
            break;
        }
        else if(str[i] < str1[i]) {
            printf("str1 is greater than str\n");
            break;
        }
        else
            i++;
    }
    if(str[i] == '\0')
        printf("%s and %s are equal\n",str,str1);
}
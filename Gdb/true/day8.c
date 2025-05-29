#include "header.h"

void re_repeat_char() {
    char str[64];
    int i,j;
    printf("Entring str to repeat char\n");
    scanf("%s",str);
    for(i=0;str[i];i++) {
        for(j=i+1;str[j];j++) {
            if(str[i] == str[j]) {
                memmove(str+j,str+j+1,strlen(str+j+1)+1);
                j--;
            }
        }
    }
    printf("output str = %s\n",str);
}

static char * u_strstr(char *str1, char *str2) {
    int i,j=0,k=0;
    for(i=0;str1[i];i++) {
        if(str1[i] == str2[j]) {
            k=i;
            for(j;str2[j];j++) {
                if(str1[k++] != str2[j]) {
                    j=0;
                    break;  
                }
            }
        }
        if(str2[j] == '\0')
            return str1+i;
    }
}

void user_strstr() {
    char str1[64],str2[32],*ptr=NULL;
    printf("Enter main str and substr\n");
    scanf("%s %s",str1,str2);
    ptr=u_strstr(str1,str2);
    printf("sub str = %s\n",ptr);
}

int bin_sea(int *arr,int l,int r,int x) {
    int m;
    while(l<=r) {
        m=l+(r-l)/2;
        if(arr[m] == x)
            return 1;
        if(arr[m] < x)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
    
}
 void binary_search() {
    int arr[]={10,15,23,27,32},n,res=0,x;
    n=sizeof(arr)/sizeof(arr[0]);
    scanf("%d",&x);
    res=bin_sea(arr,0,n-1,x);
    ((res == 1)?printf("%d:found\n",x):printf("%d:not found\n",x));
 }

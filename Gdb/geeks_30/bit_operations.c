#include "header.h"

void swap_msb_lsb() {
    unsigned int num = 0x12345678;  // Example input: 0x12345678
    unsigned int swapped_num = (num<<24 | (num & 0x00ffff00) | (num >> 24));
    
    printf("Original number: 0x%08X\n", num);
    printf("Swapped number:  0x%08X\n", swapped_num);
    
    // return 0;
}


int uanagram(char *str, char *str1) {
    int i=0,j=0,flag=0;
    if(strlen(str) != strlen(str1))
        return 0;
    for(i=0;str[i];i++) {
        flag=0;
        for(j=0;str1[j];j++) {
            if(str[i] == str1[j]) {
                flag=1;
                break;
            }
        }
        out:
            if(flag == 0)
                return 0;
    }
    return 1;
}
void anagram() {
    char str[64],str1[64];
    printf("Enter two strings\n");
    scanf("%s %s",str,str1);
    if(uanagram(str,str1))
        printf("strings are anagrams\n");
    else
        printf("strings are not anagrams\n");
}
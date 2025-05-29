#include "header.h"

char* getnext(char *str, const char delim)
{
	int i,len=0;
  char *ptr=NULL;
  static char *o_str;
    if(str != NULL)
        o_str=str;

    if(o_str == NULL)
	    return NULL;
    str=o_str;
  ptr=str;
  len=strlen(str);
  for(i=0;i<=len;i++) {
    	if(str[i] == delim || str[i] == '\0' ) {
	  if(str[i] == '\0') {
		  o_str=NULL;
		  goto end;
	  }
          str[i]='\0';
          o_str=str+i+1;
          break;
        }
  }
	end:
  return ptr;
}

void ustrtok()
{
   char str[]= "The quick brown fox jumped over the fence.";
   char delim = ' ';
   char *token = NULL;
   
   token = getnext(str, delim);
   while (token) {
	       printf("%s \n", token);
         token = getnext(NULL, delim);
   }
}
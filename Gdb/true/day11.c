#include "header.h"
struct cll {
    int num;
    char str[64];
    struct cll *link;
};
void cll_display(struct cll *ptr) {
    struct cll *temp=NULL;
    temp=ptr;
    do {
        printf("num = %d str = %s\n",temp->num,temp->str);
        temp=temp->link;
    }while((temp != ptr));
}
struct cll *add_cll(struct cll *ptr) {
    struct cll *newnode=NULL,*temp=NULL,*prev=NULL;
    newnode=(struct cll *)calloc(1,sizeof(struct cll));
    printf("Enter num and string\n");
    scanf("%d %s",&newnode->num,newnode->str);
    if(ptr == NULL) {
        ptr=newnode;
        newnode->link=ptr;
    }
    else {
        temp=ptr;
        do {
            prev=temp;
          temp=temp->link;  
        }while((temp != ptr) );
        prev->link=newnode;
        newnode->link=ptr;
    }
    return ptr;
}
struct cll *add_cll_beg(struct cll *ptr) {
    struct cll *newnode=NULL,*temp=NULL,*prev=NULL;
    newnode=(struct cll *)calloc(1,sizeof(struct cll));
    printf("Enter num and string\n");
    scanf("%d %s",&newnode->num,newnode->str);
    if(ptr == NULL) {
        ptr=newnode;
        newnode->link=ptr;
    }
    else {
        temp=ptr;
        do {
            prev=temp;
          temp=temp->link;  
        }while((temp != ptr));
        prev->link=newnode;
        newnode->link=ptr;
        ptr=newnode;
    }
    return ptr;
}
struct cll *add_cll_posn(struct cll *ptr,int posn) {
    struct cll *newnode=NULL,*temp=NULL,*prev=NULL;
    int cnt=0;
    newnode=(struct cll *)calloc(1,sizeof(struct cll));
    printf("Enter num and string\n");
    scanf("%d %s",&newnode->num,newnode->str);
    if(ptr == NULL) {
        ptr=newnode;
        newnode->link=ptr;
    }
    else {
        temp=ptr;
        do {
            prev=temp;
          temp=temp->link;
          cnt++;
        }while((temp != ptr) && (cnt<posn));
        newnode->link=prev->link;
        prev->link=newnode;
    }
    return ptr;
}
struct cll *cll_del_beg(struct cll *ptr) {
    struct cll *temp=NULL,*prev=NULL;
    temp=ptr;
    do {
        prev=temp;
        temp=temp->link;
    }while(temp != ptr);
    prev->link=ptr->link;
    temp=ptr;
    ptr=ptr->link;
    free(temp);
    return ptr;
}

struct cll *cll_del_last(struct cll *ptr) {
    struct cll *temp=NULL,*prev=NULL,*pprev=NULL;
    temp=ptr;
    do {
        pprev=prev;
        prev=temp;
        temp=temp->link;
    }while(temp != ptr);
    pprev->link=ptr;
    free(prev);
    return ptr;
}

struct cll *cll_del_posn(struct cll *ptr,int posn) {
    struct cll *temp=NULL,*prev=NULL;
    int cnt=0;
    temp=ptr;
    do {
        prev=temp;
      temp=temp->link;
      cnt++;
    }while((temp != ptr) && (cnt<posn));
    prev->link=temp->link;
    free(temp);
    return ptr;
}
void cll() {
    int i,n,posn=0;
    struct cll *head=NULL;
    printf("Enter number of nodes to add\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        head=add_cll(head);
    }
    cll_display(head);
    //head=add_cll_beg(head);
    //cll_display(head);
    //printf("Enter posn to add\n");
    //scanf("%d",&posn);
     //head=add_cll_posn(head,posn);
    //cll_display(head);
    //head=cll_del_beg(head);
    //printf("After fst node deletion\n");
    //cll_display(head);
    head=cll_del_last(head);
    printf("After Last node deletion\n");
    cll_display(head);
    
    printf("Enter posn to delete\n");
    scanf("%d",&posn);
    head=cll_del_posn(head,posn);
    printf("After Last node deletion\n");
    cll_display(head);
    
}
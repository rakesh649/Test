#include "header.h"
struct data {
    int num;
    char name[64];
    struct data *link;
};

void display(struct data *ptr) {
    while(ptr) {
        printf("num = %d name = %s\n",ptr->num,ptr->name);
        ptr=ptr->link;
    }
}

struct data *add_posn(struct data *ptr, int posn) {
    struct data *newnode=NULL,*temp=NULL,*prev=NULL;
    int cnt=0;
    newnode=(struct data *)calloc(1,sizeof(struct data));
    if(newnode == NULL)  {
        fprintf(stderr,"Memory allcoation failed\n");
        return NULL;
    }
    printf("Enter number & name\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL) 
        ptr=newnode;
    else if(posn == 0) {
        newnode->link=ptr;
        ptr=newnode;
    }
    else {
        for(temp=ptr;( (cnt<posn) && temp);cnt++,temp=temp->link) {
            prev=temp;
        }
        prev->link=newnode;
        newnode->link=temp;
    }
    return ptr;
}
struct data *add_beg(struct data *ptr) {
    struct data *newnode=NULL,*temp=NULL;
    newnode=(struct data *)calloc(1,sizeof(struct data));
    if(newnode == NULL) {
        fprintf(stderr,"Memory allcoation failed\n");
        return -1;
    }
    printf("Enter number & name to add at beg\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL)
        ptr=newnode;
    else {
        newnode->link=ptr;
        ptr=newnode;
    }
    return ptr;
}
struct data *add_last(struct data *ptr) {
    struct data *newnode=NULL,*temp=NULL;
    newnode=(struct data *)calloc(1,sizeof(struct data));
    if(newnode == NULL) {
        fprintf(stderr,"Memory allcoation failed\n");
        return -1;
    }
    printf("Enter number & name\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL) 
        ptr=newnode;
    else {
        for(temp=ptr;temp->link != NULL;temp=temp->link);
            temp->link=newnode;
           // ptr=newnode;
    }
    return ptr;
}
struct data *delete_beg(struct data *ptr) {
    struct data *temp=NULL;
    temp=ptr;
    ptr=ptr->link;
    temp->link=NULL;
    free(temp);
    return ptr;
}

struct data *delete_last(struct data *ptr) {
    struct data *prev=NULL,*temp=NULL;
        for(temp=ptr;temp->link != NULL;temp=temp->link)
            prev=temp;
        prev->link=NULL;
        free(temp);
    return ptr;
}
struct data *delete_posn(struct data *ptr,int posn) {
    struct data *temp=NULL,*prev=NULL;
    int cnt=0;
    for(temp=ptr;( (cnt<posn) && temp);cnt++,temp=temp->link) {
        prev=temp;
    }
    if(posn == 0) {
        ptr=delete_beg(ptr);
        return ptr;
    }
    prev->link=temp->link;
    free(temp);
    return ptr;
}
void add_sll() {
    int i,n,posn=0;
    struct data *head=NULL;
    printf("Enter number of nodes to be added\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        head=add_last(head);
    }
    display(head);
    head=add_beg(head);
    display(head);
    // printf("Enter posn to add\n");
    // scanf("%d",&posn);
    // head=add_posn(head,posn);
    // display(head);
    // head=delete_beg(head);
    // printf("After deleting fst node\n");
    // display(head);
    
    // head=delete_last(head);
    // printf("After deleting last node\n");
    // display(head);
    
    printf("Enter posn to delete\n");
    scanf("%d",&posn);
    head=delete_posn(head,posn);
     display(head);
}


